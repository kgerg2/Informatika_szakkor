#include <stdio.h>

int main(){
	int hossz, i;
	FILE *be;
	be = fopen("domino.be", "r");
	fscanf(be, "%d\n", &hossz);
	int lista[hossz][2];
	i = 0;
	for(i=0;i<hossz;i++){
		fscanf(be, "%d %d\n", &lista[i][0], &lista[i][1]);
	}
	printf("%d\n", hossz);
	i = 0;
	while(i<hossz){
		printf("%d %d\n", lista[i][0], lista[i][1]);
		i++;
	}
	fclose(be);
	return 0;
}
