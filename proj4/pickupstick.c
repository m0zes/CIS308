#include "pickupstick.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

extern pstick *data;

bool Add(int vertex, int edge) {
	if (vertex > data->current) {
		return false;
	}

	data->pile[vertex][data->pile[vertex][0]] = edge;
	data->visited[edge] = 1;

	return true;
}

/*
 * Check function. The logic here is that 
 */
bool Check() {
	return DFS();
}

bool DFS() {
	int i, root;
	root = 0;

	for (i = 0; i < data->current; i++) {
		if (data->visited[i] == 0)
			root = i;
		data->visited[i] = 0;
	}
	RDFS(root);
	int temp = data->visited[0];
	if (temp == 0) {
		return false;
	}
	for (i = 1; i < data->current; i++) {
		if (data->visited[i] == 0) {
			return false;
		}
		if ((temp != data->visited[i]) || ((data->visited[i] == temp) && (temp == 1)))
			temp = -1;
	}
	if (temp != -1) {
		return false;
	}
	return true;
}

void RDFS(int vertex) {
	data->visited[vertex]++;
	int i;
	for (i = 1; i < data->pile[vertex][0]; i++) {
		int v = data->pile[vertex][i];
		if (data->visited[v] < 2)
			RDFS(v);
	}
}




