#include <stdio.h>

int main(){
	int a,b,x;
	printf("Adj meg egy pozitív számot: ");
	scanf("%d", &x);
	a = 0;
	for(b=0;b*b<x;b=b+1){
		a = a+b*b;
	}
	printf("A számnál kisebb négyzetszámok összege %d.\n",a);
	return 0;
}
