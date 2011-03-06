#include <stdlib.h>
#include <stdio.h>
#include "io.h"
#include "pickupstick.h"

extern pstick *data;

int main() {
	int currdata[2];
	readLine(stdin, currdata);
	data = malloc(sizeof(pstick));
	data->pile = malloc(2*sizeof(int*));
	data->mlength = 0;
	data->current = 0;
	data->pilelen = 0;
	data->uniqlen = 0;
	while ((currdata[0] != 0) && (currdata[1] != 0)) {
		data->uniq = calloc(currdata[1], sizeof(int));
		if (data->mlength == 0) {
			data->pile[0] = malloc(currdata[1]*sizeof(int));
			data->pile[1] = malloc(currdata[1]*sizeof(int));
			data->mlength = currdata[1];
		} else if (data->mlength < currdata[1]) {
			data->pile[0] = (int*) realloc(data->pile[0], currdata[1]*sizeof(int));
			data->pile[1] = (int*) realloc(data->pile[1], currdata[1]*sizeof(int));
			data->mlength = currdata[1];
		}
		data->pilelen = currdata[1];
		int i;
		for (i = 0; i < currdata[1]; i++) {
			//printf("%d\n", currdata[1]);
			int currline[2];
			readLine(stdin, currline);
			Add(currline);
		}
		if (Check())
			print("VALID");
		else
			print("IMPOSSIBLE");
		readLine(stdin, currdata);
		free(data->uniq);
	}
	free(data->pile[0]);
	free(data->pile[1]);
	free(data->pile);
	free(data);
	return 0;
}

