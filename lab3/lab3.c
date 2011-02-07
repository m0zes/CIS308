#include <stdlib.h>
#include <stdio.h>

void print(int* val);

int main() {
	int* arr = malloc(sizeof(int) * 10);
	if (arr == NULL)
		return 10;
	int i;
	for(i=1; i<=10; i++) {
		arr[i-1] = i;
		print(&i);
	}
	free(arr);
	return 0;
}

void print(int* val) {
	printf("%d\n", *val);
}
