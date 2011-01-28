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

/*
 * Main function. Allocates memory for a buffer, and reads in a char array.
 * Adjusts the "end" of the array so that calculations won't go past the \0
 * character. calls the recursive functions revDigits and sumDigits to do the
 * obvious. Frees the buffer and returns 0
 */
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

/*
 * sumDigits function. digits is a character array of the "digits" of the int
 * s is the amount of remaining digits to be added. This function Adds all of
 * the digits of a number together, taking into account that single digits from
 * char are the numbers between 48-58. returns the sum of all the remaining 
 * digits of the number
 */
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

/*
 * revDigits reverses the character order in an array. digits is a character
 * array that contains the digits to reverse. s is the length of the remaining
 * characters of the array. returns an int of the reversed digits
 */
int revDigits(char* digits, int s) {
	int amtSub = 1;
	if( s < (LengthOfArray/2)) {
		char tmp = digits[s];
		digits[s] = digits[( LengthOfArray - amtSub) - s];
		digits[( LengthOfArray - amtSub) - s] = tmp;
		revDigits(digits, ++s);
	}
	return atoi(digits);
}

/*
 * countDigits simply counts the number of characters until a \0, and returns
 * the number of of digits up until that character.
 */
int countDigits(char* digits, int s) {
	int i;
	for(i=0;i<s;i++) {
		if (digits[i] == '\0')
			return i-1;
	}
	return LengthOfArray;
}
