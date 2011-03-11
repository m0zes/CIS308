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
	data->pile[0][data->current] = tuple[0]-1;
	data->pile[1][data->current] = tuple[1]-1;
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
	int **out  = malloc(2 * sizeof(int*));
	out[0] = malloc(data->pilelen * sizeof(int));
	out[1] = malloc(data->pilelen * sizeof(int));
	Multiply(out, data->pilelen);
	for (i = 0; i < data->pilelen; i++) {
		if (out[0][i] == out[1][i]) {
			printf("out[0][%d] (%d) == out[1][%d] (%d)\n", i, out[0][i], i, out[1][i]);
			printf("data->pile[0][%d] was %d\n", i, data->pile[0][i]);
			retval = false;
		}
	}
	free(out[0]);
	free(out[1]);
	free(out);
	if (retval == true)
		printf("returning true\n");
	return retval;
}

void Multiply(int **out, int length) {
	int i, j;
	//printf("length = %d\n", length);
	for (i = 0; i < data->current; i++) {
		if (data->pile[0][i] == 0) {
			printf("was %d, now %d\n", data->pile[0][i], length-1);
			out[0][i] = length - 1;
		} else {
			//printf("was %d, now %d\n", data->pile[0][i], data->pile[0][i]-1);
			out[0][i] = data->pile[0][i]-1;
		}
		out[1][i] = data->pile[1][i];
	}
}
