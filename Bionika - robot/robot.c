#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int mozog(int lepes){
	int i, oszto=2;
	for(i=0;i<lepes;i++){
		oszto *= 2;
	}
	if(50/oszto==0){
		return 1;
	}
	return 50/oszto;
}

int main(){
	int i, j, k, polc[50], temp, min, max, lepes, vege, poz, keres=850, lepesek[10000];
	srand((unsigned int) time(NULL));
	//for(k=0;k<10000;k++){
	max = rand()%1000+1000;
	max = 850;
	for(i=0;i<50;i++){
		polc[i] = rand()%max;
		do{
			temp = 0;
			for(j=0;j<i;j++){
				if(polc[j]==polc[i]){
					polc[i] = rand()%max;
					temp = 1;
				}
			}
		}while(temp==1);
	}
	polc[49] = 850;
	for(i=0;i<50;i++){
		min = 49;
		for(j=i;j<50;j++){
			if(polc[j]<polc[min]){
				min = j;
			}
		}
		temp = polc[i];
		polc[i] = polc[min];
		polc[min] = temp;
	}
	/*for(i=0;i<50;i++){
		printf("%d\n", polc[i]);
	}*/
	lepes = 1;
	vege = 0;
	poz = 25;
	while(vege==0){
		printf("\t%d (%d)\n", poz, polc[poz]);
		if((polc[poz]<keres && polc[poz+1]>keres) || (polc[poz-1]<keres && polc[poz]>keres)){
			vege = -1;
		}
		if(polc[poz]<keres){
			poz += mozog(lepes);
			lepes++;
		} else if(polc[poz]>keres){
			poz -= mozog(lepes);
			lepes++;
		} else{
			vege = 1;
		}
	}
	printf("%d\n", lepes);
	lepesek[k] = lepes;
	//}
	/*for(i=0;i<10000;i++){
		printf("%2d ", lepesek[i]);
	}*/
	return 0;
}
