/* 
 * Lab2 -- read names.txt 1/line, write hello name, print yes/no for double letters
 */

#include <stdio.h>

int checkDouble(char* name);

int main() {
	FILE *fp = fopen("names.txt", "r");
	if (fp == NULL) {
		printf("Error opening file");
		return 1;
	}
	char name[30];
	while (fscanf(fp, "%s", name) != EOF) {
		printf("Hello, %s\n", name);
		if (checkDouble(name))
			printf("Yes\n");
		else
			printf("No\n");
	}

	fclose(fp);
}
	
int checkDouble(char* name) {
	int i;
	for( i = 0; i < 29; i++) {
		if(name[i+1] == '\0')
			break;
		if( name[i] == name[i+1])
			return 1;
	}
	return 0;
}
