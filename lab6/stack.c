#include "stack.h"

extern struct LinkedChar *head;

void Push(char c) {
	struct LinkedChar *newList;
	newList = malloc(sizeof(struct LinkedChar));
	newList->Character = c;
	if (head == NULL) {
		head = newList;
		newList->nextChar = NULL;
	} else {
		newList->nextChar = head;
		head = newList;
	}
}

char Pop() {
	if (head != NULL) {
		struct LinkedChar *tmpPtr;
		tmpPtr = head->nextChar;
		char c = head->Character;
		free(head);
		head = tmpPtr;
		return c;
	}
	return '\0';
}

int Size() {
	struct LinkedChar *tmpPtr;
	tmpPtr = head;
	int count = 0;
	while (tmpPtr != 0) {
		tmpPtr = tmpPtr->nextChar;
		count++;
	}
	return count;
}
