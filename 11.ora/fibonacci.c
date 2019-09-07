#include <stdio.h>
int db, maxdb, felo;
int fibonacci(int fmost){
	int fkov;
	if(db==maxdb){
		felo = 0;
		fmost = 1;
	}
	fkov = felo+fmost;
	felo = fmost;
	if(db<=2){
		return fkov;
	} else{
		db--;
		return fibonacci(fkov);
	}
}

int main(){
	printf("Add meg, hogy a fibonacci-sorozat hányadik elemét kéred:");
	scanf("%d", &db);
	maxdb = db;
	printf("Az ennyiedik elem: %d.\n", fibonacci(db));
	return 0;
}
