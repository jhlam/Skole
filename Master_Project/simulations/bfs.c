#include <stdbool.h>
int total_nodes = 10;


int distGen(int dist[total_nodes], int level, bool x[total_nodes], bool y[total_nodes]){
	int update = 0;
	for (int i= 0; i<total_nodes; i++){
		if(x[i]== 0 & y[i]==1){
			dist[i] = level;
			update+=1;
		}
	}
	return update;
}

// This function performs a single step of sparse matrix vector multiplication
// *Changing to
int * SpMV(int A[total_nodes][total_nodes], bool x[total_nodes], bool y[total_nodes]){

	//This is one step in the SpMV
	bool result = false;
	for(int idy = 0; idy<total_nodes; idy++){
		for (int idx = 0; idx<total_nodes; idx++){
			if(A[idy][idx] && x[idx]){
				result = result || A[idy][idx] && x[idx];

			}
		}
		y[idy]= result;
	}
	return y;
}

int * bfsAsLinearAlgebra(int A[total_nodes], int root, bool x[total_nodes], bool y[total_nodes], int dist[total_nodes]){
	for(int i = 0; i<total_nodes; i++){
		dist[i]= -1;
	}

	int level = 1;
	int converged = 0;
	while(!converged){
		SpMV(A,x,y);
		converged = distGen(dist, level, x,y);
		x =y;
		level += 1;
	}
	return dist;
}