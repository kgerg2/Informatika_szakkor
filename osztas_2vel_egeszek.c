#include <stdio.h>

int main(){
	int n, szam, i;
	printf("Adj meg egy pozitív egész számot: ");
	scanf("%d", &n);
	szam = 0;
	
	for(i=1;i<=n;i=i+1){
		if(i%2 == 0){
			szam = szam + 1;
		}
	}
	printf("Ebben a számban a kettő %d egésszer van meg.\n",szam);
	return 0;
}
