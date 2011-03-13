/******************************************************************************
 * Name: Adam Tygart                                                          *
 * Date: 03/13/2011                                                           *
 * Assignment: Project 4: Pick up Sticks                                      *
 ******************************************************************************
 * 11686 - Pick up sticks                                                     *
 * Read stdin until 0 0\n occurs. first line will be two ints n and m. n is   *
 * the number of sticks, m is the number of lines following for this problem  *
 * set. n and m will be between 1 and 1000000. the following lines will be    *
 * integers a and b, a being a stick number and b being the stick that a lies *
 * on top of.                                                                 *
 * Read in this information and see if the pile can be "picked up" according  *
 * the rules of pickup-sticks.                                                *
 ******************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include "io.h"
#include "pickupstick.h"

extern pstick *data;

/*
 * main, calls between io.c and pickupstick.c readin in stdin and checking to 
 * see if the pile can be picked up.
 */
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
			int *new = (int*) realloc(data->pile[vertex], 
					(data->pile[vertex][0]+1) * sizeof(int*));
			data->pile[vertex] = new;
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

