#include <stdio.h>

int main(){
	int i, hossz, poz, fa, lepes, maxfa, max, kezd;
	scanf("%d", &hossz);
	int lista[hossz][2];
	for(i=0;i<hossz;i++){
		scanf("%d %d", &lista[i][0], &lista[i][1]);
	}
	poz = 0;
	fa = 0;
	lepes = 1;
	max = 0;
	maxfa = 0;
	while(fa<hossz){
		if(lista[fa][0]+lista[fa][1]>poz){
			poz = lista[fa][0]+lista[fa][1];
		}
		kezd = fa-1;
		if(kezd<0){
			kezd = 0;
		}
		while(fa<hossz && poz>=lista[fa][0]){
			printf("\t%d %d, %d ->", lista[fa][0], lista[fa][1], poz);
			if(lista[fa][0]+lista[fa][1]>poz){
				poz = lista[fa][0]+lista[fa][1];
			}
			printf("%d\n", poz);
			fa++;
		}
		if(fa-kezd>max){
			maxfa = kezd;
			max = fa-kezd;
		}
		if(fa<hossz){
			printf("\t%d %d, %d, %d, max: %d (%d)\n", lista[fa][0], lista[fa][1], poz, lepes, maxfa, max);
			lepes++;
			fa++;
		}
	}
	printf("%d\n", lepes);
	printf("%d\n", maxfa+1);
	return 0;
}
