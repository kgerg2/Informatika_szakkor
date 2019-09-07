# include <stdio.h>

int main(){
	int x, y, t, i, j, xa, ya, xb, yb;
	FILE *fa;
	printf("Hello!\n");
	fa = fopen("negyz_nov.svg","w");
	fprintf(fa, "<svg width='210' height='210' xmlns='http://www.w3.org/2000/svg' version='1.1'>\n");
	
	for(t=0;t<11;t++){
		printf("t:%d\n", t);
		for(x=100;x>=100-10*t;x=x-10){
			y = 200-10*t-x;
			printf("x: %d\n", x);
			printf("y: %d\n", y);
			for(i=0;i<=t;i=i+t+1){
				xa = x-10*i;
				ya = y+10*i;
				printf("i: %d\n", i);
				for(j=0;j<=t;j=j+1){
					xb = xa+10*j;
					yb = ya+10*j;
					printf("j: %d\n", j);
					fprintf(fa, "\t<rect x='%d' y='%d' width='10' height='10' stroke='white' fill='white'>\n\t\t<animate\n\t\t\tattributeName='fill'\n\t\t\tattributeType='XML'\n\t\t\tfrom='white' to='black'\n\t\t\tbegin='%ds' dur='500ms'\n\t\t\tfill='freeze'\n\t\t/>\n\t</rect>\n", xb, yb, t);
				}
			}
		}
	}
	
	fprintf(fa,"\n</svg>");
	fclose(fa);
	return 0;
}
