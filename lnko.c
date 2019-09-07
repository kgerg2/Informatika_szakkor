#include <stdio.h>

int main(){
	int a, b, x;
	
	printf("Add meg az egyik számot: ");
	scanf("%d", &a);
	printf("Add meg a másik számot: ");
	scanf("%d", &b);
	
	for(x=0;a%x!=0 || b%x!=0;x=x+1){
		
	}
	printf("A két szám legnagyobb közös osztója: %d.\n",x-1);
	
	return 0;
}
