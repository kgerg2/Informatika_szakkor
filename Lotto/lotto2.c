#include <stdio.h>

/*struct szamok{
	int min;
	int kis;
	int koz;
	int nagy;
	int max;
}*/

int main(){
	//struct szamok het[52];
	int i, j, k, uthet[5], het[52][5], maxpoz, darabszam[91];
	i = 0;
	maxpoz = 0;
	for(i=0;i<91;i++){
		darabszam[i] = 0;
	}
	//Fájl olvasása
	
	FILE *fa;
	fa = fopen("lottosz.dat", "r");
	while(!feof(fa)){
		fscanf(fa, "%d %d %d %d %d\n", &het[i][0], &het[i][1], &het[i][2], &het[i][3], &het[i][4]);
		i++;
	}
	fclose(fa);
	
	//Az utolsó hét
	
	/*printf("Add meg az 52. hét számait szóközzel elválasztva: ");
	scanf("%d %d %d %d %d", &uthet[0], &uthet[1], &uthet[2], &uthet[3], &uthet[4]);
	for(j=4;j>=0;j--){
		for(i=0;i<5;i++){
			if(uthet[maxpoz]<uthet[i]){
				maxpoz = i;
			}
		}
		het[51][j] = uthet[maxpoz];
		uthet[maxpoz] = 0;
	}
	for(i=0;i<5;i++){
		printf("%d ", het[51][i]);
	}
	printf("\n");
	
	printf("Hányadik hét adatait kéred az [1;51]-ről:");
	scanf("%d", &i);
	printf("Az e heti lottószámok: ");
	for(j=0;j<5;j++){
		printf("%d ", het[i-1][j]);
	}
	printf("\n");
	
	for(i=1;i<91;i++){
		for(j=0;j<51;j++){
			for(k=0;k<5;k++){
				if(i==het[j][k]){
					darabszam[i]++;
				}
			}
		}
	}
	for(i=0;i<90;i++){
		if(darabszam[i]==0){
			//printf("%d\n", i+1);
			j = 0;
		}
	}
	if(j==0){
		printf("Van hiányzó szám.\n");
	} else {
		printf("Nincs hiányzó szám.\n");
	}
	for(j=0;j<51;j++){
		for(k=0;k<5;k++){
			if(het[j][k]%2==0){
				i++;
			}
		}
	}
	printf("%d db páratlan számot húztak ki.\n", i);
	
	ki = fopen("lotto52.ki", "w");
	for(i=0;i<52;i++){
		fprintf(ki, "%d %d %d %d %d\n", het[i][0], het[i][1], het[i][2], het[i][3], het[i][4]);
	}
	fclose(ki);*/
	return 0;
}
