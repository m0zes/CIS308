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
#ifndef PICKUPSTICK_H
#define PICKUPSTICK_H

enum BOOLEAN  
{
	false,
	true 
};

typedef enum BOOLEAN bool;

struct PICKUPSTICK {
	int *visited;
	int **pile;
	int current;
};

typedef struct PICKUPSTICK pstick;

pstick *data;

bool Add(int, int);

bool Check();

bool DFS();

void RDFS(int vertex);

#endif
