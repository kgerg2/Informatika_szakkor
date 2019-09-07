#include <stdio.h>

int main(){
	int talal, h, eh, keres;
	printf("Add meg, hogy mekkora vízállásokat keressek:");
	scanf("%d", &keres);
	FILE *fa;
	fa = fopen("vizallas.txt","r");
	eh = 0;
	talal = 0;
	while(!feof(fa)){
		eh = h;
		fscanf(fa, "%d\n", &h);
		if(eh<=keres && h>keres){
			talal = talal+1;
		}
		if(eh>keres && h<=keres){
			talal = talal+1;
		}
	}
	printf("%d alkalommal volt %d cm a vízállás.", talal, keres);
	fclose(fa);
	return 0;
}
