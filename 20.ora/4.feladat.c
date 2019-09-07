#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int i, j, k, ppoz[3], jo, ossz=0, sok=1000000;
	double varh_ert;
	srand((unsigned int) time(NULL));
	for(i=0;i<sok;i++){
		jo = 0;
		while(jo==0){
			ppoz[0] = rand()%8;
			ppoz[1] = rand()%8;
			ppoz[2] = rand()%8;
			if(ppoz[0]!=ppoz[1] && ppoz[1]!=ppoz[2] && ppoz[0]!=ppoz[2]){
				jo = 1;
			}
		}
		jo = 0;
		for(j=0;j<3;j++){
			for(k=0;k<3;k++){
				if(ppoz[j]==k){
					jo++;
				}
			}
		}
		//printf("%d %d %d\n%d\n", ppoz[0], ppoz[1], ppoz[2], jo);
		ossz = ossz+jo;
	}
	varh_ert = (double)ossz/(double)sok;
	printf("A varhato ertek %f (kb. 1,1249).\n", varh_ert);
	return 0;
}

