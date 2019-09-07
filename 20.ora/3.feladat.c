#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int i, j, k, dob, ert, fpoz[3], jo, ossz=0, sok=1000000;
	double vszg;
	srand((unsigned int) time(NULL));
	for(i=0;i<sok;i++){
		jo = 0;
		while(jo==0){
			fpoz[0] = rand()%7;
			fpoz[1] = rand()%7;
			fpoz[2] = rand()%7;
			if(fpoz[0]!=fpoz[1] && fpoz[1]!=fpoz[2] && fpoz[0]!=fpoz[2]){
				jo = 1;
			}
		}
		jo = 0;
		for(j=0;j<3;j++){
			for(k=0;k<2;k++){
				if(fpoz[j]==k){
					jo++;
				}
			}
		}
		jo = 2-jo;
		ert = 0;
		for(j=0;j<jo;j++){
			dob = rand()%6+1;
			ert = ert+dob;
		}
		if(ert>4){
			ossz++;
		}
		//printf("%d %d %d\n%d\n", fpoz[0], fpoz[1], fpoz[2], jo);
	}
	vszg = (double)ossz/(double)sok;
	printf("A valoszinuseg %f (kb. 0,4285).\n", vszg);
	return 0;
}
