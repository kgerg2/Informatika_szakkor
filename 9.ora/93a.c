#include <stdio.h>

int main(){
	int ar, maxar, h, nap, knap, vnap;
	FILE *fa;
	fa = fopen("vizallas.txt","r");
	ar = 0;
	maxar = 0;
	nap = 0;
	vnap = 0;
	
	while(!feof(fa)){
		fscanf(fa, "%d\n", &h);
		nap = nap+1;
		if(h>=800){
			ar = ar+1;
			if(ar>maxar){
				maxar = ar;
				vnap = nap;
			}
		} else {
			ar = 0;
		}
	}
	knap = vnap-maxar+1;
	printf("A leghosszabb árvízveszélyes idõszak %d napig tartott az év %d. napjától a %d. napig.", maxar, knap, vnap);
	fclose(fa);
	
	return 0;
}
