#include <stdio.h>

int main(){
	printf("Hello!\n");
	int i, j, k, uthet[5], het[52][5], maxpoz, darabszam[91];
	i = 0;
	maxpoz = 0;
	for(i=0;i<91;i++){
		darabszam[i] = 0;
	}
	FILE *fa;
	fa = fopen("lottosz.dat", "r");
	while(!feof(fa)){
		//fscanf(fa, "%d %d %d %d %d\n", &het[i][0], &het[i][1], &het[i][2], &het[i][3], &het[i][4]);
		for(j=0;j<4;j++){
			fscanf(fa, "%d ", &het[i][j]);
		}
		fscanf(fa, "%d\n", &het[i][5]);
		i++;
	}
	fclose(fa);
	return 0;
}
