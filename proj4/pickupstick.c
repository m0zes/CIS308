#include "pickupstick.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

extern pstick *data;

bool Add(int *tuple) {
	if (tuple[0] > data->pilelen) {
		return false;
	}
	data->pile[0][data->current] = tuple[0]-1;
	data->pile[1][data->current] = tuple[1]-1;
	data->current++;

	AddUniq(tuple[0]-1);
	return true;
}

void AddUniq(int j) {
	if (data->uniq[j] == false) {
		data->uniq[j] = true;
		data->uniqlen++;
	}
}

/*
 * Check function. The logic here is that 
 */
bool Check() {
	int i, j, k;
	bool retval = true;
	int uniqc = data->uniqlen;
	for (i = 0; i < data->uniqlen; i++) {
		for (k = 0; k < data->uniqlen; k++) {
			if (data->uniq[i] == false) {
				for (j = 0; j < data->current; j++) {
					data->pile[0][j] = -1;
					data->pile[1][j] = -1;
				}
			} else {
				for (j = 0; j < data->current; j++) {
					if (data->pile[1][j] == i)
						break;
				}
				if (j == data->current) {
					data->uniq[i] = false;
					uniqc--;
				}
			}
		}
	}

	if (uniqc != 0) {
		retval = false;
	}
	return retval;
}
