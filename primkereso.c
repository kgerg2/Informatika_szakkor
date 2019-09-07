#include <stdio.h>

int prim_e(int p){
	int i;
	
	i = 2;
	while(p%i!=0 && i<=p/2){
		i=i+1;
	}
	
	if(i>p/2){
		return 1;
	} else{
		return 0;
	}
}


int main(){
	int szam, i;
	
	printf("Kérek egy pozitív egész számot, ahonnan keresem a prímeket: ");
	scanf("%d", &szam);	
	
	while(prim_e(szam)==0){
		szam = szam+1;
	}
	
	printf("\nA megtalált prím értéke %d.\n", szam);

	
	for(i=1;i<10;i++){
		printf("%d\n", i);
	}
	
	return 0;
}

