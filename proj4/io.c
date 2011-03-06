#include "io.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

bool readLine(FILE *fp, int *out) {
	fscanf(fp, "%d %d", &out[0], &out[1]);
	// eat a char (\n)
	getchar();
	//printf("read %d %d\n", out[0], out[1]);
	//if (out[0] == NULL)
	//	return false;
	return true;
}

void print(char *out) {
	printf("%s\n", out);
}
