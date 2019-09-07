#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){
	int szam, i;
	
	srand((unsigned int) time(NULL));
	for(i=0;i<21;i++){
		szam = rand();
		szam = szam%100+100;
		printf("%d\n", szam);
	}
	return 0;
}
