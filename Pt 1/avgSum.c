/* Assignment2pt1
	aveSum.c
	
	a function that computes the sum and average of an array, which has length n. 

*/
#include <stdio.h>
#include <stdlib.h>

void aveSum(double a[], int n, double *avg, double *sum){
	
	//printf("here2\n");
	
	*sum = 0.0;
	
	//printf("here3\n");
	
	for(int i = 0; i < n; i++){
		*sum = *sum + a[i];
	}	
	
	*avg = *sum/n;
}

int main(){
	
	int n = 6;
	double array[6] = {1, 2, 3, 4, 5, 6};
	double *average = malloc(sizeof(double));
	double *sum = malloc(sizeof(double));
	
	
	//printf("here\n");

	aveSum(array, n, average, sum);
	
	//printf("here 22\n");
	printf("\nAverage: %f\n Sum: %f\n", *average, *sum);
}