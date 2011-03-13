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
#include "pickupstick.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

extern pstick *data;

/*
 * Add. adds the vertex and edge to the adjacency list. also indicates whether
 * a vertex has been seen before.
 * vertex, the stick on on top of the edge
 * edge, the stick underneath the vertex
 * returns whether or not the stick was able to be added.
 */
bool Add(int vertex, int edge) {
	if (vertex > data->current) {
		return false;
	}
	data->pile[vertex][data->pile[vertex][0]] = edge;
	data->visited[edge] = 1;
	return true;
}

/*
 * Check function. Simply calls the DFS function. there was more logic here at 
 * one point in time.
 * returns the output of the DFS function.
 */
bool Check() {
	return DFS();
}

/*
 * Sets up the depth first search.
 * Finds an unvisited vertex, calling it root, and starts the RDFS on it
 * Once RDFS has finished, it checks the visited array for unvisited nodes,
 * and nodes makes sure that every node is visited either once, or that it 
 * be visited only once.
 * returns true if the pile can be solved, false if not.
 */
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

/*
 * RDFS - the recursive depth first search function.
 * traverses the adjaceny matrix, "visiting" each node at least twice.
 * vertex is the vertex int the adjacency list it should visit.
 */
void RDFS(int vertex) {
	data->visited[vertex]++;
	int i;
	for (i = 1; i < data->pile[vertex][0]; i++) {
		int v = data->pile[vertex][i];
		if (data->visited[v] < 2)
			RDFS(v);
	}
}




