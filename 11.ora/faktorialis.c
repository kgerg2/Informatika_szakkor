#include <stdio.h>

int fakt(int k){
	if(k==1){
		return 1;
	} else{
		return k*fakt(k-1);
	}
}

int main(){
	int n;
	printf("Kérek egy pozitív egészet: ");
	scanf("%d", &n);
	printf("A faktoriális: %d\n", fakt(n));
	return 0;
}
