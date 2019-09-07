#include <stdio.h>

int main(){
	
	int a,b;
	
	printf("Add meg egy egész számot: ");
	scanf("%d", &b);
	printf("Add meg, hogy mennyivel osztva keressem az osztási maradékát: ");
	scanf("%d", &a);
	
	for(a=a;a>=b;a=a-b){
	}
	
	printf("Az osztási maradék: %d.\n",a);
	
	return 0;
}
