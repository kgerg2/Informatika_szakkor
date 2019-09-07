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
	
	int x, y, t, i;
	FILE *fa;
	printf("Hello!");
	fa = fopen("negyz_nov.svg","w");
	fprintf(fa, "<svg width='210' height='210' xmlns='http://www.w3.org/2000/svg' version='1.1'>\n");
	
	for(t=0;t<11;t++){
		for(x=100;x>=100-10*t;x=x-10){
			y = 200-10*t-x;
			for(i=0;i<t;i++){
				x = x+10*i;
				y = y+10*i;
				fprintf(fa, "\t<rect x='%d' y='%d' width='10' height='10' stroke='white' fill='white'>\n\t\t<animate\n\t\t\tattributeName='fill'\n\t\t\tattributeType='XML'\n\t\t\tfrom='white' to='black'\n\t\t\tbegin='%ds' dur='500ms'\n\t\t\tfill='freeze'\n\t\t/>\n\t</rect>\n", x, y, t);
			}
		
		}
	}
	
	fprintf(fa,"\n</svg>");
	fclose(fa);
	return 0;
}
