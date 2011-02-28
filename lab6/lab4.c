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

int main() {
	fprintf(stdout, "Input a word: \n");
	char buff[80];
	scanf("%s", buff);
	int count = 0;
	for ( count = 0; count < 80; count++) {
		if (buff[count] != '\0') {
			Push(buff[count]);
		} else {
			break;
		}
	}

	int size = Size();

	for(count = 0; count < size; count++) {
		printf("%c", Pop());
	}
	printf("\n");
	return 0;
}

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
