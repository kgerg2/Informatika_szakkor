#include <stdio.h>

int main(){
	int n, k, t;
	
	printf("Add meg az egyik számot: ");
	scanf("%d", &n);
	printf("Add meg a másik számot: ");
	scanf("%d", &k);
	
	for(t=n;t%n!=0 || t%k!=0;t=t+1){
	}
	printf("A két szám lekisebb közös többszöröse %d.\n",t);
}
