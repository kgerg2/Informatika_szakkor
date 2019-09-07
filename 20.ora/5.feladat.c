#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int i, dob, ertek, ossz=0, sok=1000000;
	double varh_ert;
	srand((unsigned int) time(NULL));
	for(i=0;i<sok;i++){
		ertek = 0;
		dob = 3;
		while(dob==3){
			dob = rand()%3+1;
			//printf("%d ", dob);
			ertek = ertek+dob;
		}
		ossz = ossz+ertek;
		//printf("\n%d\n", ertek);
	}
	varh_ert = (double)ossz/(double)sok;
	printf("A varhato ertek %f (kb. 3).\n", varh_ert);
	return 0;
}
