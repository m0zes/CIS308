#include <stdlib.h>
#include <stdio.h>
#include "io.h"
#include "pickupstick.h"

extern pstick *data;

int main() {
	int currdata[2];
	readLine(stdin, currdata);
	data = malloc(sizeof(pstick));
	while ((currdata[0] != 0) && (currdata[1] != 0)) {
		data->visited = calloc(currdata[0], sizeof(int));
		data->pile = malloc(currdata[0] * sizeof(int*));
		data->current = currdata[0];
		int i;
		for (i = 0; i < currdata[0]; i++) {	
			data->pile[i] = malloc(sizeof(int));
			data->pile[i][0] = 1;
		}
		for (i = 0; i < currdata[1]; i++) {
			int currline[2];
			readLine(stdin, currline);
			int vertex = currline[0]-1;
			int edge = currline[1]-1;
			int *new = (int*) realloc(data->pile[vertex], (data->pile[vertex][0]+1) * sizeof(int*));
			data->pile[vertex] = new;
			//printf("i = %d, data->pile[vertex][0] (%d) = %d\n", i, vertex, data->pile[vertex][0]);
			Add(vertex, edge);
			data->pile[vertex][0]++;
		}
		if (Check())
			print("VALID");
		else
			print("IMPOSSIBLE");
		for (i = 0; i < currdata[0]; i++) {	
			free(data->pile[i]);
		}
		free(data->pile);
		free(data->visited);
		readLine(stdin, currdata);
	}
	free(data);
	return 0;
}

