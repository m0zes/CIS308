#include <stdlib.h>
#include "io.h"
#include "pickupstick.h"

extern pstick *data;

int main() {
	int currdata[2];
	readLine(stdin, currdata);
	while ((currdata[0] != 0) && (currdata[1] != 0)) {
		if (data->mlength < currdata[1]) {
			data->pile = realloc(data->pile, currdata[1]*sizeof(int*));
			data->uniq = realloc(data->pile, currdata[1]*sizeof(int));
			data->mlength = currdata[1];
		}
		data->pilelen = currdata[1];
		int i;
		for (i = 0; i < currdata[1]; i++) {
			int currline[2];
			readLine(stdin, currline);
			Add(currline);
		}
		if (Check())
			print("VALID");
		else
			print("IMPOSSIBLE");
		readLine(stdin, currdata);
	}
	int j;
	for (j = 0; j < data->mlength; j++) {
		free(data->pile[j]);
	}
	free(data->pile);
	free(data->uniq);
	return 0;
}

