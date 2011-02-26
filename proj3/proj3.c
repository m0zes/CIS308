/*************************************************
 * Name: Adam Tygart                             *
 * Date: Feb 27, 2011                            *
 * Assignment: Project 3: Matrix Multiplication  *
 *************************************************
 * multiplies the matrices specified in the file * 
 * on the cli                                    *
 *************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 * Creates a Matrix struct that holds information about a 2d matrix
 */
struct Matrix {
	int rows;
	int columns;
	int **data;
};

/*
 * adds a new data type called matrix. it is a struct Matrix
 */
typedef struct Matrix matrix;

/*
 * macro doing simple multiplication
 */
#define multiply(a, b) a*b;

int matrixMultiply(matrix *m1, matrix *m2, matrix *out);
void printMatrix(matrix *m);


/*
 * main. reads in the file specified on the command line, creates matrices from it
 * multiplies the matrices and prints the output matrix
 * return value is for posix compliance. 0 is success, everything else is failure
 * argc is the number of cli arguments in the argv
 * argv is a array of strings holding the cli arguments
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

	// read matrix 1
	fscanf(fp, "%s\n", buff);
	matrix *m1 = malloc(sizeof(matrix)); 
	m1->rows = atoi(buff);
	m1->data = malloc(m1->rows * sizeof(int*));
	fscanf(fp, "%s\n", buff);
	m1->columns = atoi(buff);
	int i;
	for (i=0;i<m1->rows;i++) {
		m1->data[i] = malloc(m1->columns * sizeof(int));
		fgets(buff, 80, fp);
		char *result = strtok(buff, " ");
		m1->data[i][0] = atoi(result);
		int j;
		for (j=1; j < m1->columns; j++) {
			m1->data[i][j] = atoi(strtok(NULL, " "));
		}
	}

	printf("The first matrix is:\n");
	printMatrix(m1);

	// eat a line out of the file
	fgets(buff, 80, fp);

	// read matrix 2
	fscanf(fp, "%s\n", buff);
	matrix *m2 = malloc(sizeof(matrix)); 
	m2->rows = atoi(buff);
	m2->data = malloc(m2->rows * sizeof(int*));
	fscanf(fp, "%s\n", buff);
	m2->columns = atoi(buff);
	for (i=0;i<m2->rows;i++) {
		m2->data[i] = malloc(m2->columns * sizeof(int));
		fgets(buff, 80, fp);
		char *result = strtok(buff, " ");
		m2->data[i][0] = atoi(result);
		int j;
		for (j=1; j < m2->columns; j++) {
			m2->data[i][j] = atoi(strtok(NULL, " "));
		}
	}
	printf("The second matrix is:\n");
	printMatrix(m2);

	// create out matrix
	matrix *out = malloc(sizeof(matrix));
	out->rows = m1->rows;
	out->columns = m2->columns;
	out->data = malloc(out->rows * sizeof(int*));
	for (i = 0; i < out->rows; i++)
		out->data[i] = calloc(out->columns, sizeof(int));

	int errCode;

	if (matrixMultiply(m1, m2, out)) {
		printf("Their product is:\n");
		printMatrix(out);
		errCode = 0;
	} else {
		printf("matrix multiplication is impossible. exiting.\n");
		errCode = 95;
	}

	//cleanup
	for (i = 0; i < m1->rows; i++)
		free(m1->data[i]);
	for (i = 0; i < m2->rows; i++)
		free(m2->data[i]);
	for (i = 0; i < out->rows; i++)
		free(out->data[i]);
	free(m1->data);
	free(m2->data);
	free(out->data);
	free(m1);
	free(m2);
	free(out);

	fclose(fp);

	return errCode;
}

/*
 * prints the rows and columns of a matrix
 * matrix m is the matrix to print
 */
void printMatrix(matrix *m) {
	int i, j;
	for (i = 0; i < m->rows; i++) {
		for (j = 0; j < m->columns; j++)
			printf("\t%i", m->data[i][j]);
		printf("\n");
	}
	printf("\n");
}

/*
 * multiplies a matrix. optimized for speed as ikj is a bit faster than ijk
 * returns an int indicating whether the multiply happened.
 * m1 is the primary matrix. m2 is the secondary matrix
 * out is the output matrix.
 */
int matrixMultiply(matrix *m1, matrix *m2, matrix *out) {
	if (m1->columns == m2->rows) {
		int i, j, k;
		out->rows = m1->rows;
		out->columns = m2->columns;
		for (i = 0; i < out->rows; i++)
			for (k = 0; k < m1->columns; k++)
				for (j = 0; j < out->columns; j++)
					out->data[i][j] += multiply(m1->data[i][k], m2->data[k][j]);
		return 1;
	}
	return 0;
}

