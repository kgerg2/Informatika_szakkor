#include <stdio.h>

int main(){
	int a, b, maxa, maxb, max;
	max  = 0;
	maxa = 0;
	maxb = 0;
	
	for(a=0;a<=1000;a++){
		for(b=0;b<=1000;b++){
			if((a+1)*b+(b+1)*a<=1000){
				if(a*b>max){
					max  = a*b;
					maxa = a;
					maxb = b;
				}
			}
		}
	}
	
	printf("A legjobb megoldás: \n\t a = %d\n", maxa);
	printf("\t b = %d\n", maxb);
	printf("Ennek területe: %d\n", max);
	
	return 0;
}
