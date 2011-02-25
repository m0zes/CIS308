#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Matrix {
	int rows;
	int columns;
	int **data;
};

typedef struct Matrix matrix;

matrix *multiply(matrix *m1, matrix *m2);
void printMatrix(matrix *m);

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
		fscanf(fp, "%s\n", buff);
		char *result = strtok(buff, " ");
		m1->data[i][0] = atoi(result);
		int j;
		for (j=1; j < m1->columns; j++) {
			m1->data[i][j] = atoi(strtok(NULL, " "));
		}
	}
	printMatrix(m1);

	// eat a line out of the file
	fscanf(fp, "%s\n", buff);

	// read matrix 2
	fscanf(fp, "%s\n", buff);
	matrix *m2 = malloc(sizeof(matrix)); 
	m2->rows = atoi(buff);
	m2->data = malloc(m2->rows * sizeof(int*));
	fscanf(fp, "%s\n", buff);
	m2->columns = atoi(buff);
	for (i=0;i<m2->rows;i++) {
		m2->data[i] = malloc(m2->columns * sizeof(int));
		fscanf(fp, "%s\n", buff);
		char *result = strtok(buff, " ");
		m2->data[i][0] = atoi(result);
		int j;
		for (j=1; j < m2->columns; j++) {
			m2->data[i][j] = atoi(strtok(NULL, " "));
		}
	}
	printMatrix(m2);

	multiply(m1, m2);	

	int errCode = 95;


	return 0;
}
