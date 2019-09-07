#include <stdio.h>

int main(){
	int x, y, t, i, j, xa, ya, xb, yb;
	FILE *fa;
	fa = fopen("negyz_nov.svg","w");
	fprintf(fa, "<svg width='210' height='210' xmlns='http://www.w3.org/2000/svg' version='1.1'>\n");
	//Balra fel
	for(t=0;t<11;t++){
		for(x=100;x>=100-10*t;x=x-10){
			y = 200-10*t-x;
			for(i=0;i<=t;i=i+t+1){
				xa = x-10*i;
				ya = y+10*i;
				fprintf(fa, "\t<rect x='%d' y='%d' width='10' height='10' stroke='white' fill='white'>\n\t\t<animate\n\t\t\tattributeName='fill'\n\t\t\tattributeType='XML'\n\t\t\tfrom='white' to='black'\n\t\t\tbegin='%ds' dur='500ms'\n\t\t\tfill='freeze'\n\t\t/>\n\t</rect>\n", xa, ya, t);
			}
		}
	}
	//Balra le
	for(t=0;t<11;t++){
		for(x=100;x>=100-10*t;x=x-10){
			y = 10*t+x;
			for(i=0;i<=t;i=i+t+1){
				xa = x+10*i;
				ya = y+10*i;
				fprintf(fa, "\t<rect x='%d' y='%d' width='10' height='10' stroke='white' fill='white'>\n\t\t<animate\n\t\t\tattributeName='fill'\n\t\t\tattributeType='XML'\n\t\t\tfrom='white' to='black'\n\t\t\tbegin='%ds' dur='500ms'\n\t\t\tfill='freeze'\n\t\t/>\n\t</rect>\n", xa, ya, t);
			}
		}
	}
	//Jobbra le
	for(t=0;t<11;t++){
		for(x=100;x<=100+10*t;x=x+10){
			y = 200+10*t-x;
			for(i=0;i<=t;i=i+t+1){
				xa = x-10*i;
				ya = y+10*i;
				fprintf(fa, "\t<rect x='%d' y='%d' width='10' height='10' stroke='white' fill='white'>\n\t\t<animate\n\t\t\tattributeName='fill'\n\t\t\tattributeType='XML'\n\t\t\tfrom='white' to='black'\n\t\t\tbegin='%ds' dur='500ms'\n\t\t\tfill='freeze'\n\t\t/>\n\t</rect>\n", xa, ya, t);
			}
		}
	}
	//Jobbra fel
	for(t=0;t<11;t++){
		for(x=100;x<=100+10*t;x=x+10){
			y = x-10*t;
			for(i=0;i<=t;i=i+t+1){
				xa = x-10*i;
				ya = y-10*i;
				fprintf(fa, "\t<rect x='%d' y='%d' width='10' height='10' stroke='white' fill='white'>\n\t\t<animate\n\t\t\tattributeName='fill'\n\t\t\tattributeType='XML'\n\t\t\tfrom='white' to='black'\n\t\t\tbegin='%ds' dur='500ms'\n\t\t\tfill='freeze'\n\t\t/>\n\t</rect>\n", xa, ya, t);
			}
		}
	}
	fprintf(fa,"\n</svg>");
	fclose(fa);
	return 0;
}
