#include <stdio.h>

int main(){
	int a, b, maxa, maxb, max, gyufa;
	max  = 0;
	maxa = 0;
	maxb = 0;
	
	printf("Add meg, hány gyufát hassználhatunk: ");
	scanf("%d", &gyufa);
	
	for(a=0;a<=gyufa;a++){
		for(b=0;b<=gyufa;b++){
			if((a+1)*b+(b+1)*a<=gyufa){
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
	printf("%d gyufát használtunk fel.\n", (maxa+1)*maxb+(maxb+1)*maxa);
	return 0;
}
