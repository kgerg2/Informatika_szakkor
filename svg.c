#include <stdio.h>

int main(){
	printf("Hello!");
	FILE *fa;
	
	fa = fopen("vmi.svg", "w");
	fprintf(fa, "<svg width='100' height='200' xmlns='http://www.w3.org/2000/svg' version='1.1'>\n");
	
	fprintf(fa,"\t<rect x='10' y='10' width='50' height='50' stroke='black' fill='black'>\n\t</rect>\n");
	
	fprintf(fa,"</svg>");
	fclose(fa);
	
	printf("Hello!");
	return 0;
}
