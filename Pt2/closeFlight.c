/* Assignment 2 part 2
	closeFlight.c
	
	Jaret Griggs - 3254792
	
	A program that takes a time in from user input then compares it to a list of flights from a file
	(flights.dat) and returns the closest time
*/
#include <stdlib.h>
#include <stdio.h>

int findClosestFlight(int desiredTime, int *departureTime, int *arrivalTime){
	
	FILE *f = fopen("flights.dat", "r");
	
	int hours = 0;
	int mins = 0;
	
	int check = fscanf(f,"%d:%d", &hours, &mins);
	//printf("\n%02d:%02d\n", hours, mins);//test code
	
	if(check == 2){
		*departureTime = mins + (hours*100);
		check = fscanf(f,"%d:%d", &hours, &mins);
		if(check == 2){
			*arrivalTime = mins + (hours*100);
		}
		else
		{
			printf("error1");
			return 2;
		}
	}
	else{
		printf("error2");
		return 2;
	}
	
	
	while(check ==2){
		if(desiredTime <= *departureTime){
			return 1;
		}
		else{
			check = fscanf(f,"%d:%d", &hours, &mins);
	
			if(check == 2){
				*departureTime = mins + (hours*100);
				check = fscanf(f,"%d:%d", &hours, &mins);
				if(check == 2){
					*arrivalTime = mins + (hours*100);
				}
				else
				{
					printf("error3");
					return 2;
				}
			}
		}
	}
	
	return 0;
}


int main(){
	
	int hours = 0;
	int mins = 0;
	int desiredTime = 0;
	int *departureTime = malloc(sizeof(int));
	int *arrivalTime = malloc(sizeof(int));
	
	printf("Enter a 24-hour time: ");
	scanf("%d:%d", &hours, &mins);
	
	desiredTime = mins + (hours*100);
	*departureTime = 0;
	*arrivalTime = 0;
	
	//For testing
	mins = 0;
	hours = 0;
	
	//printf("%2d", desiredTime);// testing
	
	int check = findClosestFlight(desiredTime, departureTime,arrivalTime);
	
	
	if(check == 1){
		mins = *departureTime % 100;
		hours = (*departureTime - mins)/100;
		printf("\nClosest Departure time is %02d:%02d,", hours, mins);
		mins = *arrivalTime % 100;
		hours = (*arrivalTime - mins)/100;
		printf(" arriving at %02d:%02d\n", hours, mins);
	}
	else if(check == 0){
		printf("Sorry, No avaiable departures\n");
	}
}