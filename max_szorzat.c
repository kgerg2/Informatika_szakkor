#include <stdio.h>

int main(){
	int a, b, maxa, maxb, max;
	maxa = 0;
	maxb = 0;
	max = 0;
	for(a=0;a<=20;a++){
		for(b=0;b<=20;b++){
			if(a=20 || a>max){
				a = maxa;
				b = maxb;
				max = a*b;
			}
		}
	}
	
	
	return 0;
}
