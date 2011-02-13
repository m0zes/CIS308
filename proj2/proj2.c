/********************************************************************
 * Name: Adam Tygart                                                *
 * Date: 02-16-11                                                   *
 * Assignment: Project 2: Jagged Arrays                             *
 ********************************************************************
 * Read a file, containing lists. sort the lists, then the elements *
 ********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sink(int **wholeArray, int *singlePiece, int root, int bottom); 
void sortArrays(int **array, int *sizes, int length);
void printArrays(int **array, int *sizes, int length);

/*
 * main runs the program. reads from a file on the command line, stores the
 * arrays contained therein, sorts and prints the arrays.
 *
 * argc is the number of command line arguments.
 * argv is an array of strings with a length of 1+argc
 */
int main(int argc, char **argv) {
	if(argc <= 1) {
		fprintf(stderr, "Please specify a filename on the command line.");
		return 10;
	}
	FILE *fp = fopen(argv[1], "r");
	if(fp == NULL) {
		fprintf(stderr, "Couldn't open the file");
		return 20;
	}
	char buff[80];
	fscanf(fp, "%s\n", buff);
	int count = atoi(buff);
	int **arr = malloc(count * sizeof(int*));
	int *sizes = malloc(count * sizeof(int));
	int errCode = 95;
	if ((arr != NULL) && (sizes != NULL)) {
		int i;
		for(i = 0; i < count; i++) {
			char buff[80];
			fgets(buff, 80, fp);
			char *result = strtok(buff, " ,:");
			int length = atoi(result);
			sizes[i] = length;
			arr[i] = malloc((length) * sizeof(int));
			if ( arr[i] == NULL )
				break;
			int j;
			for (j=0; j < length; j++) {
				result = strtok(NULL, " ,:");
				arr[i][j] = atoi(result);
			}

			sortArrays(NULL, arr[i], length);
		}

		sortArrays(arr, sizes, count);

		printArrays(arr, sizes, count);
		errCode=0;
	}

	fclose(fp);

	int j;
	for (j = 0; j < count ; j++)
		free(arr[j]);
	free(sizes);
	free(arr);
	return errCode;
}

/*
 * sortArrays is a modified HeapSort.
 * wholeArray in this case is the multidimensional array holding pointers to
 * other arrays. May be NULL, to sort one array.
 * singlePiece is a int array, will be the list that is sorted.
 * length is the length of the array in question. (length of wholeArray and
 * singlePiece are equal)
 *
 * Algorithm from http://www.sorting-algorithms.com/heap-sort
 */
void sortArrays(int **wholeArray, int *singlePiece, int length) {
	int i, v;
	int *vPtr;
	for (i = (length / 2); i >= 0; i--)
		sink(wholeArray, singlePiece, i, length - 1);

	for (i = length - 1; i >= 1; i--) {
		v = singlePiece[0];
		singlePiece[0] = singlePiece[i];
		singlePiece[i] = v;
		if (wholeArray != NULL) {
			vPtr = wholeArray[0];
			wholeArray[0] = wholeArray[i];
			wholeArray[i] = vPtr;
		}
		sink(wholeArray, singlePiece, 0, i - 1);
	}
}

/*
 * sink is the other half of the modified HeapSort
 * wholeArray in this case is the multidimensional array holding pointers to
 * other arrays. May be NULL, to sort one array.
 * singlePiece is a int array, will be the list that is sorted.
 * root is the index to start
 * bottom is index to stop
 *
 * Algorithm from http://www.sorting-algorithms.com/heap-sort
 */
void sink(int **wholeArray, int *singlePiece, int root, int bottom) {
	int done, max, v;
	int *vPtr;
	done = 0;

	while ((root * 2 <= bottom) && (!done)) {
		if ((root * 2 == bottom ) || (singlePiece[root * 2] > singlePiece[root * 2 + 1]))
			max = root * 2;
		else
			max = root * 2 + 1;

		if (singlePiece[root] < singlePiece[max]) {
			v = singlePiece[root];
			singlePiece[root] = singlePiece[max];
			singlePiece[max] = v;
			if (wholeArray != NULL) {
				vPtr = wholeArray[root];
				wholeArray[root] = wholeArray[max];
				wholeArray[max] = vPtr;
			}
			root = max;
		}
		else
			done = 1;
	}
}

/*
 * printArrays prints the contents of the arrays to the screen.
 * array is the multidimensional array containing the data to print
 * sizes is the lengths of the inner dimensional arrays
 * length is the length of the outer arrays and sizes.
 */
void printArrays(int **array, int *sizes, int length) {
	int i;
	for (i=0; i < length; i++) {
		int j;
		//printf("%d: ", sizes[i]);
		for (j=0; j < sizes[i]; j++) {
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
}
