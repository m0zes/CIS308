#ifndef PICKUPSTICK_H
#define PICKUPSTICK_H

enum BOOLEAN  
{
	false,
	true 
};

typedef enum BOOLEAN bool;

struct PICKUPSTICK {
	int *uniq;
	int uniqlen;

	int **pile;
	int current;
	int pilelen;
	int mlength;
};

typedef struct PICKUPSTICK pstick;

pstick *data;

bool Add(int*);

bool Check();

void Multiply(int**, int**, int**, int);

void Swap(int***, int***);

void AddUniq(int);

#endif
