#include <stdio.h>

int main(){
	int max, i, j, k, ek, rak;
	rak = 0;
	FILE *fa;
	FILE *fb;
	fa = fopen("pakol.be","r");
	fb = fopen("pakol.ki","w");
	fscanf(fa, "%d\n", &max);
	max++;
	int a[max];
	max--;
	for(i=1;i<=max;i++){
		fscanf(fa, "%d ", &a[i]);
		printf("a[%d]=%d\n", i, a[i]);
	}	
	for(j=1;j<=max;j++){
		printf("j=%d\na[j]=%d\n", j, a[j]);		
		if(a[j]!=0){
			k = a[j];
			while(k!=j){
				printf("k=%d, a[k]=%d", k, a[k]);				
				ek = k;
				k = a[k];
				a[ek] = 0;
				rak = rak+1;
				printf("\trak=%d\n", rak);
			}
			rak = rak-1;
		}
	}
	printf("rak=%d", rak);
	
	fprintf(fb,"%d", rak);
	fclose(fb);
	fclose(fa);
	
	return 0;
}
