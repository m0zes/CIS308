#include "pickupstick.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

extern pstick *data;

bool Add(int *tuple) {
	if (tuple[0] > data->pilelen) {
		//printf("tuple[0] (%d) is less than data->pilelen (%d)\n", tuple[0], data->pilelen);
		return false;
	}
	data->pile[0][data->current] = tuple[0];
	data->pile[1][data->current] = tuple[1];
	//printf("data->pile[0][%d] = %d\n", data->current, data->pile[0][data->current]);
	//printf("data->pile[1][%d] = %d\n", data->current, data->pile[1][data->current]);
	data->current++;

	//printf("data->pile[%d] added %d %d\n", data->current-1, tuple[0], tuple[1]);
	AddUniq(tuple[0]);
	return true;
}

void AddUniq(int j) {
	//if (data->uniqlen == 0) {
	//	printf("returning early\n");
	//	data->uniq[0] = j;
	//	data->uniqlen++;
	//	return;
	//}
	//int i;
	//for (i = 0; i < data->uniqlen; i++) {
	//	if (data->uniq[i] == j) {
	//		//printf("breaking because data->uniq[i] == j (%d %d)\n", data->uniq[i], j);
	//		break;
	//	} else if ((data->uniq[i] > j) || (data->uniq[i] == 0)) {
	//		int k = data->uniqlen + 1;
	//		while (k > i) {
	//			//printf("moving %d to %d\n",data->uniq[k], k+1);
	//			data->uniq[k+1] = data->uniq[k];
	//			k--;
	//		}
	//		//printf("Adding %d\n", j);
	//		data->uniq[i] = j;
	//		data->uniqlen = data->uniqlen+1;
	//		break;
	//	}
	//}
	if (data->uniq[j] == 0) {
		data->uniq[j] = 1;
		data->uniqlen++;
	}
}

/*
 * Check function. The logic here is that 
 */
bool Check() {
	int i;
	bool retval = true;
	//int **mat2 = malloc(2 * sizeof(int*));
	int **out  = malloc(2 * sizeof(int*));
	out[0] = malloc(data->pilelen * sizeof(int));
	out[1] = malloc(data->pilelen * sizeof(int));
	//mat2[0] = calloc(data->pilelen, sizeof(int));
	//mat2[1] = calloc(data->pilelen, sizeof(int));
	//memmove(data->pile[0],mat2[0], data->pilelen * sizeof(int));
	//memmove(data->pile[1],mat2[1], data->pilelen * sizeof(int));
	//for (i = 0; i < data->uniqlen; i++) {
		//Multiply(data->pile, mat2, out, data->pilelen);
	//	Swap(&mat2, &out);
	//}
	Multiply(out, data->uniqlen);
	for (i = 0; i < data->pilelen; i++) {
		//printf("out[0][%d] (%d), out[1][%d] (%d)\n", i, out[0][i], i, out[1][i]);
		if (out[0][i] == out[1][i]) {
			printf("out[0][%d] (%d) == out[1][%d] (%d)\n", i, out[0][i], i, out[1][i]);
			retval = false;
		}
	}
	//free(mat2[0]);
	free(out[0]);
	//free(mat2[1]);
	free(out[1]);
	//free(mat2);
	free(out);
	if (retval == true)
		printf("returning true\n");
	return retval;
}

void Multiply(int **out, int length) {
	int i;
	//for (i = 0; i < length; i++) {
	//	for (j = 0; j < length; j++) {
	//		if (mat1[1][i] == mat2[0][i]) {
	//			out[0][i] = mat1[0][i];
	//			out[1][i] = mat2[1][i];
	//		}
	//	}
	//}
	//printf("length = %d\n", length);
	for (i = 0; i < data->current; i++) {
		if (data->pile[0][i] == 1) {
			//printf("top\n");
			out[0][i] = length;
		} else {
			//printf("bottom\n");
			out[0][i] = data->pile[0][i] - 1;
		}
		out[1][i] = data->pile[1][i];
		//printf("Was data->pile[0][%d] = %d, out[0][%d] = %d\n", i, data->pile[0][i], i, out[0][i]);
	}
}

void Swap(int ***m1, int ***m2) {
	int **temp;
	temp = *m1;
	*m1 = *m2;
	*m2 = temp;
}
