#include <stdio.h>

int main(){
	int a, b, i;
	
	printf("Add meg a nagyobb számot: ");
	scanf("%d", &a);
	printf("Add meg a kisebb számot:  ");
	scanf("%d", &b);
	
	for(a=a;a>=b;a=a-1){
		i = 2;
		while(a%i!=0 && i<=a/2){
			i = i+1;		
		}
		if(i>a/2){
			printf("%d\n",a);
		}
	}
	
	return 0;
}
