#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#include <stdlib.h>

struct LinkedChar {
	char Character;
	struct LinkedChar *nextChar;
};

struct LinkedChar *head;

void Push(char c);
char Pop();
int Size();
#endif
