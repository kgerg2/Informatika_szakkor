#include <stdio.h>

int main(){
	int max, i, j, rak;
	rak = 0;
	FILE *fa;
	FILE *fb;
	fa = fopen("pakol.be","r");
	fb = fopen("pakol.ki.txt","w");
	fscanf(fa, "%d\n", &max);
	int a[max];
	for(i=0;i<max;i++){
		fscanf(fa, "%d ", &a[i]);
	}
	for(max=max;max>0;max=max-1){
		for(i=0;i<max;i++){
			if(a[i]==max){
				rak = rak+max-i-1;
				for(j=i;j<max;j++){
					a[j] = a[j+1];
				}
				//A max. helyre rakom a i+1. helyen lévő könyvet. Így már rak lépést csináltam.
				i = max;
			}
		}
	}
	fprintf(fb,"%d", rak);
	fclose(fa);
	fclose(fb);
	
	return 0;
}
