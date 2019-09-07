#include <stdio.h>

int main(){
	int szam;
	FILE *fa;
	
	fa = fopen("szamok.csv","r");
	
	while(!feof(fa)){
		fscanf(fa,"%d\n", &szam);
		printf("%d\n", szam);
	}
	
	fclose(fa);
	
	return 0;
}
