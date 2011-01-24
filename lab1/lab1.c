#include <stdio.h>

int calc(int val);

int main() {
	int input;
	printf("input a number greater than or equal to 0\n");
	scanf("%d", &input);
	int output;
	if( input < 0) {
		printf("Error: value must be >= 0\n");
		return 30;
	} else
		output = calc(input);
	printf("Value is %d\n", output);
	return 0;
}

int calc(int val) {
	int x = 0;
	int output = 0;
	while ( x <= val ) {
		output += x;
		x++;
	}
	return output;
}
