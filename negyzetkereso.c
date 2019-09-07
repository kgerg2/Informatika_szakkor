#include<stdio.h>

int main(){
	int a,b,x;
	printf("Adj meg egy pozitív számot: ");
	scanf("%d", &x);
	b = 0;
	for(a=0;b*b<x;a=a+b*b){
		b = b+1;
	}
	if(b*b>=x){
		a = a-b*b;
	}
	printf("A számnál kisebb négyzetszámok összege %d.\n",a);
	
}
