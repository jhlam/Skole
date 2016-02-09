#include <stdbool.h>


int p_i = 50; // the global probability



int distGen(int dist[], int level, bool x[], bool y[]);

bool * SpMV(int A[], bool x[], bool y[]);

int * bfsAsLinearAlgebra(int A[], int root, bool x[], bool y[], int dist[]);
