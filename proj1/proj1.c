/***********************************************
 * Name: Adam Tygart
 * Date: 2/2/11
 * Assignment: Project 1: Integer Operations
 ***********************************************
 * Input an integer, and outputs the reverse of the number and the sum of the 
 * digits. Utilize recursive functions.
 ***********************************************/

#include <stdio.h>
#include <stdlib.h>
int LengthOfArray = 11;
int sumDigits(char* digits, int s);
int revDigits(char* digits, int s);
int countDigits(char* digits, int s);

int main() {
	char* buff;
	buff = (char*) malloc( sizeof(char) * LengthOfArray);

	printf("Enter a number: ");
	fgets(buff, LengthOfArray, stdin);
	LengthOfArray = countDigits(buff, LengthOfArray);
	printf("\nReversed: %d\n", revDigits(buff, 0));
	printf("Sum of Digits: %d\n\n", sumDigits(buff, LengthOfArray));

	free(buff);
	return 0;
}

int sumDigits(char* digits, int s) {
	if( s > 0 ) {
		if(( (int) digits[s] > 48) && ( (int)digits[s] < 58 ))
			return ((int)digits[s] - 48) + sumDigits(digits, --s);
		else 
			return sumDigits(digits, --s);
	} else {
		if(( (int) digits[s] > 48) && ( (int)digits[s] < 58 ))
			return ((int)digits[s] - 48);
	}
	return 0;
}

int revDigits(char* digits, int s) {
	if( s < LengthOfArray/2) {
		char tmp = digits[s];
		digits[s] = digits[( LengthOfArray - (LengthOfArray%2)) - s];
		digits[( LengthOfArray - (LengthOfArray%2)) - s] = tmp;
		revDigits(digits, ++s);
	}
	return atoi(digits);
}

int countDigits(char* digits, int s) {
	int i;
	for(i=0;i<s;i++) {
		if (digits[i] == '\0')
			return i;
	}
	return -1;
}
