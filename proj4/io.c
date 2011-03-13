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
#include "io.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * readLine, reads in two integers, and eats a newline.
 * fp is the filepointer, in this case hard coded to stdin
 * out is the two int array that the digits will be read into
 * the return would tell you if the line was actually read
 */
bool readLine(FILE *fp, int *out) {
	fscanf(fp, "%d %d", &out[0], &out[1]);
	// eat a char (\n)
	char c = getchar();
	return true;
}

/*
 * print, prints out a "string"
 * out is char array to print
 */
void print(char *out) {
	printf("%s\n", out);
}
