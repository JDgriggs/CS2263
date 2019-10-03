/* 
Solves the SSSP problem for graphs with nonzero integer weights
using a version of the Bellman-Ford algorithm
Author: Eric Aubanel
Date: September 2018
*/

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>


int readGraphWeighted(int n, int m, int **graph){

	for (int i = 0; i <  n; i++) {
		for (int j = 0; j < n; j++) {
			graph[i][j] = 0;
		}
	}
  for(int i=0; i<m; i++){
    int vertexOne, vertexTwo, weight;
    if(scanf("%d %d %d",&vertexOne, &vertexTwo, &weight)!=3){
      return 0;
    }
	if(vertexOne < n && vertexTwo < n){
		graph[vertexOne][vertexTwo] = weight;
	}
	else{
		printf("\nError: invalad node\n");
		return 0;
	}
  }
  
  return 1;
}


int main(){
	
	int n, m;
	scanf("%d %d",&n, &m);
  
	//making the graph
	int *graph[n];

    for(int i=0; i<n; i++) {
        graph[i] = (int *)malloc(n * sizeof(int)); 
	}
  
	int check = readGraphWeighted(n, m, graph);
	
	if (check == 1){
		printf("\n\n");
		for (int i = 0; i <  n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d ", graph[i][j]);
			}
			printf("\n");
		}
	}
	
}

