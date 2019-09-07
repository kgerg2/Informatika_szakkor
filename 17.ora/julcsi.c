#include <stdio.h>

int lep(int n){
	if(n==3){
		return 4;
	} else if(n==2){
		return 2;
	} else if(n==1){
		return 1;
	} else{
		return lep(n-1)+lep(n-2)+lep(n-3);
	}
}

int main(){
	int n;
	printf("Hány lépcső van: ");
	scanf("%d", &n);
	printf("%d\n", lep(n));
	return 0;
}
