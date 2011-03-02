#include "io.h"
#include <stdlib.h>
#include <stdio.h>

int readLine(FILE *fp, int *out) {
	fgets("%d %d\n", out[0], out[1]);
	if (out[0] == NULL)
		return 0;
	return 1;
}


