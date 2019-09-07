#include <stdio.h>
#include <math.h>
int main(){
	float a;
	printf("Add meg a szám értékét: ");
	scanf("%f", &a);
	a = sqrt(a);
	printf("%f\n", a);
	return 0;
}
