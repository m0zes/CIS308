#ifndef PICKUPSTICK_H
#define PICKUPSTICK_H

enum BOOLEAN  
{
	false,
	true 
};

typedef enum BOOLEAN bool;

struct PICKUPSTICK {
	int *visited;
	int **pile;
	int current;
};

typedef struct PICKUPSTICK pstick;

pstick *data;

bool Add(int, int);

bool Check();

bool DFS();

void RDFS(int vertex);

#endif
