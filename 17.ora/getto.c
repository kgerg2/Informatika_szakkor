#include <stdio.h>

int lep(int x, int y){
	if(x==0){
		return 1;
	} else if(y==0){
		return 1;
	} else{
		return lep(x-1, y)+lep(x, y-1)+lep(x-1, y-1);
	}
}

int main(){
	int x, y;
	printf("Milyen széles a gettó: ");
	scanf("%d", &x);
	printf("Milyen magas a gettó: ");
	scanf("%d", &y);
	printf("%d\n", lep(x, y));
	return 0;
}

