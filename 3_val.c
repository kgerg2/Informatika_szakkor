#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
	int sor[3], val, ki, valt, jodb, i, maxdb=1000000;
	printf("Váltsak (0/1): ");
	scanf("%d", &valt);
	for(i=0;i<maxdb;i++){
		sor[0] = rand()%2;
		sor[1] = rand()%2;
		sor[2] = rand()%2;
		while(sor[0]+sor[1]+sor[2]!=1){
			sor[1] = rand()%2;
			sor[2] = rand()%2;
		}
		val = rand()%3;
		ki = rand()%3;
		while(ki==val || sor[ki]!=0){
			ki = rand()%3;
		}
		if(valt==1){
			if(ki!=0 && val!=0){
				val = 0;
			} else if(ki!=1 && val!=1){
				val = 1;
			} else if(ki!=2 && val!=2){
				val = 2;
			}
		}
		if(sor[val]==1){
			jodb++;
		}
	}
	printf("\n%d alkalommal volt helyes a tipp (ossz: %d; %2.1f%%).\n", jodb, maxdb, (double)jodb/maxdb*100);
	return 0;
}
