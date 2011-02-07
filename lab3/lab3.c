#include <stdlib.h>
#include <stdio.h>

void print(int* val, int length);

int main() {
	int* arr = malloc(sizeof(int) * 10);
	if (arr == NULL)
		return 10;
	int i;
	for(i=1; i<=10; i++) {
		arr[i-1] = i;
	}
	print(arr, 10);
	free(arr);
	return 0;
}

void print(int* val, int length) {
	int* i;
	for (i = val; i < val+length; i++)
		printf("%d\n", *i);
}
