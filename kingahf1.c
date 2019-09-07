#include <stdio.h>

int main(){
	int a, b, c, d, joa, job, joc, x, y;
	printf("Hello!");
	a = 0;
	b = 0;
	c = 0;
	for(a=0;a<10;a=a+1){
		for(b=0;b<10 || b!=a;b=b+1){
			for(c=0;c<10 || c!=a || c!=b;c=c+1){
				for(d=0;d<10 || d!=a || d!=b || d!=c;d++){
					x = a*100+b*10+c-(b*100+d*10+a);
					y = c*100+d*10+b;
					if(x==y){
						joa=a;
						job=b;
						joc=c;
					}
				}
			}
		}
	}
	printf("a = %d\n", joa);
	printf("b = %d\n", job);
	printf("c = %d\n", joc);
	return 0;
}
