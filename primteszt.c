#include<stdio.h>

int main(){
	int szam, i;
	
	printf("Kérek egy egész számot: ");
	scanf("%d", &szam);
	
	i = 2;
	while(szam%i!=0 && i<=szam/2){
		i=i+1;
	}
	
	if(i>szam/2){
		printf("\nA megadott szám %d prím.\n", szam);
	} else{
		printf("\nA megadott szám nem prím, %d osztója.\n", i);
	}
		
	return 0;
}
