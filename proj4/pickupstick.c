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
	data->current++;

	//printf("data->pile[%d] added %d %d\n", data->current-1, tuple[0], tuple[1]);
	AddUniq(tuple[0]);
	return true;
}

void AddUniq(int j) {
	if (data->uniqlen == 0) {
		data->uniq[0] = j;
		data->uniqlen++;
		return;
	}
	int i;
	for (i = 0; i < data->uniqlen; i++) {
		if (data->uniq[i] == j)
			break;
		else if (data->uniq[i] > j) {
			int k = data->uniqlen + 1;
			while (k > i) {
				data->uniq[k-1] = data->uniq[k];
				k--;
			}
			data->uniq[i] = j;
			data->uniqlen = data->uniqlen+1;
			break;
		}
	}
}

/*
 * Check function. The logic here is that 
 */
bool Check() {
	int i;
	bool retval = true;
	for (i = 0; i < data->pilelen; i++) {
		if (data->pile[0][i] - 1 <= 0) {
			printf("out: %d %d\n", data->uniqlen, data->pile[1][i]);
			if (data->uniqlen == data->pile[1][i]) {
				printf("data->pile[0][i] - 1 <= 0\n");
				retval = false;
				break;
			}
		} else {
			printf("out: %d %d\n", data->pile[0][i], data->pile[1][i]);
			if (data->pile[0][i] - 1 == data->pile[1][i]) {
				printf("data->pile[0][i] - 1 == data->pile[1][i]\n");
				retval = false;
				break;
			}
		}
	}
	return retval;
}
