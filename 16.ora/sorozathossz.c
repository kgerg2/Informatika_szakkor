#include <stdio.h>

int szamlalo, feladat;
int sorozat(int be){
	szamlalo++;
	if(feladat==2 || feladat==3){
		printf("%d ", be);
	}
	if(be%2==0){
		return sorozat(be/2);
	} else if(be==1){
		return 1;
	} else{
		return sorozat(3*be+1);
	}
}

int main(){
	int kezd;
	szamlalo = 0;
	printf("Adja meg, hogy hányadik feladat megoldását szeretné látni:\n1-1. feladat, 2-2.feladat, 3-mindkettő: ");
	scanf("%d", &feladat);
	printf("Adja meg a sorozat kezdőszámát: ");
	scanf("%d", &kezd);
	sorozat(kezd);
	if(feladat==1){
		printf("%d lépés.", szamlalo);
	} else if(feladat==3){
		printf("\n%d lépés.", szamlalo);
	}
	printf("\n");
	return 0;
}
