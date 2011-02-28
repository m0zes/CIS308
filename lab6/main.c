#include "stack.h"

extern struct LinkedChar *head;

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
