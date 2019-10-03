/* Assignment 2 part 2
	closeFlight.c
	
	Jaret Griggs - 3254792
	
	A program that takes a time in from user input then compares it to a list of flights from a file
	(flights.dat) and returns the closest time
*/
#include <stdlib.h>
#include <stdio.h>

void findClosestFlight(int desiredTime, int *departureTime, int *arrivalTime){
	
	FILE *f = fopen("flights.dat", "r");
	
	int hours = 0;
	int mins = 0;
	
	
}


int main(){
	
	int hours = 00;
	int mins = 00;
	
	printf("%d : %d\n", hours, mins);
}