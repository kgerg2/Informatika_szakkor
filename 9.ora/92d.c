#include <stdio.h>

int main(){
	int ar, h;
	FILE *fa;
	fa = fopen("vizallas.txt","r");
	ar = 0;
	while(!feof(fa)){
		fscanf(fa, "%d\n", &h);
		if(h>=800){
			ar = ar+1;
		}
	}
	printf("%d alkalommal volt árvízveszély.", ar);
	fclose(fa);
	return 0;
}
