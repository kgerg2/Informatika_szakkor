#include <stdio.h>

int main(){
	int eh, h, em;
	FILE *fa;
	fa = fopen("vizallas.txt","r");
	eh = 0;
	em = 0;
	while(!feof(fa)){
		eh = h;
		fscanf(fa, "%d\n", &h);
		if(h>eh){
			em = em+1;
		}
	}
	printf("A vízállás %d napon emelkedett.", em-1);
	fclose(fa);
	return 0;
}
