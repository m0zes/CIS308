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
#ifndef IO_H
#define IO_H

#include "pickupstick.h"
#include <stdio.h>

bool readLine(FILE*, int*);

void print(char*);

#endif
