#include "pickupstick.h"
#include <stdlib.h>
#include <string.h>

extern pstick *data;

bool Add(int *tuple) {
	if (tuple[0] > data->pilelen) {
		return false;
	}
	data->pile[data->current++] = tuple;
	AddUniq(tuple[0]);
	return true;
}

void AddUniq(int j) {
	int k;
	for (k = 1; k < j; ++k) {
		int key = data->uniq[k];
		int i = k - 1;
		while ((i >= 0) && (key < data->uniq[i])) {
			data->uniq[i + 1] = data->uniq[i];
			--i;
		}
		if (data->uniq[i] == j)
			return;
		data->uniq[i + 1] = key;
		data->uniqlen++;
	}
}

bool Check() {
	int i;
	bool retval = true;
	int **mat2 = malloc(data->pilelen * sizeof(int*));
	int **out  = malloc(data->pilelen * sizeof(int*));
	for (i = 0; i < data->pilelen; i++) {
		memcpy(data->pile[i],mat2[i], 2* sizeof(int));
		out[i] = malloc(2 * sizeof(int));
	}
	for (i = 0; i < data->uniqlen; i++) {
		Multiply(data->pile, mat2, out, data->pilelen);
		Swap(&mat2, &out);
	}
	for (i = 0; i < data->pilelen; i++) {
		if (mat2[i][0] == mat2[i][1])
			retval = false;
		free(mat2[i]);
		free(out[i]);
	}
	free(mat2);
	free(out);
	return retval;
}

void Multiply(int **mat1, int **mat2, int **out, int length) {
	int i,j;
	for (i = 0; i < length; i++) {
		for (j = 0; j < length; j++) {
			if (mat1[i][1] == mat2[i][0]) {
				out[i][0] = mat1[i][0];
				out[i][1] = mat2[i][1];
			}
		}
	}
}

void Swap(int ***m1, int ***m2) {
	int **temp;
	temp = *m1;
	*m1 = *m2;
	*m2 = temp;
}
