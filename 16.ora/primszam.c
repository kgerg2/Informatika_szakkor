#include <stdio.h>

int prim(int x){
	int i;
	for(i=2;i<=x/2;i++){
		if(x%i==0){
			return 0;
		}
	}
	return 1;
}

int main(){
	int hatar, primdb, i;
	primdb = 0;
	printf("Kérek egy pozitív egészet: ");
	scanf("%d", &hatar);
	for(i=2;i<=hatar;i++){
		if(prim(i)==1){
			primdb++;
		}
	}
	printf("A prímek száma %d-ig %d.\n", hatar, primdb);
	return 0;
}
