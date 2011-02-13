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

void sortArray(int *array, int length);
void sortArrays(int **array, int *sizes, int length);
void printArrays(int **array, int *sizes, int length);

int main(int argc, char **argv) {
	if(argc <= 1)
		return 10;
	FILE *fp = fopen(argv[1], "r");
	if(fp == NULL)
		return 20;
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

			sortArray(arr[i], length);
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


void sortArray(int *array, int length) {
	int i, j, v;
	for(i = 0; i < length; i++)
		for(j = 0; j < length-1; j++)
			if(array[j] > array[j+1]) {
				v = array[j+1];
				array[j+1] = array[j];
				array[j] = v;
			}
}

void sortArrays(int **array, int *sizes, int length) {
	int i, j, v;
	int *vPtr;
	for(i = 0; i < length; i++)
		for(j = 0; j < length-1; j++)
			if(sizes[j] > sizes[j+1]) {
				v = sizes[j+1];
				vPtr = array[j+1];
				sizes[j+1] = sizes[j];
				array[j+1] = array[j];
				sizes[j] = v;
				array[j] = vPtr;
			}
}

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
