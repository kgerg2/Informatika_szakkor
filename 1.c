#include <stdio.h>

int maci(int i){
	int x;
	
	printf("x");
	scanf("%d", &x);
	
	for(i=2;x%i!=0 && i<=x/2;i=i+1){
	}
	if(i>x/2){
		printf("return 1");
		return 1;
	} else{
		printf("return 0");
		return 0;
	}
}

int main(){
	int n, j;
	
	printf("n: ");
	scanf("%d", &n);
	
	for(j=2;j>=n;j=j){
		if(n%j == 0 && maci(j) == 1){
			printf("%d",j);
		} else{
			j = j + 1;
			printf("main j: %d",j);
		}
	}
	return 0;
}
