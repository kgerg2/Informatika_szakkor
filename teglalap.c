#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){
	int xpoz, ypoz, xmeret, ymeret, szegely, kitoltes;
	
	FILE *fa;
	
	srand((unsigned int) time(NULL));
	
	fa = fopen("teglalap.svg", "w");
	fprintf(fa, "<svg width='300' height='200' xmlns='http://www.w3.org/2000/svg' version='1.1'>\n");
	xpoz = rand()%300;
	ypoz = rand()%200;
	xmeret = rand()%(300-xpoz);
	ymeret = rand()%(200-ypoz);
	szegely = rand()%0xFFFFFF;
	kitoltes = rand()%0xFFFFFF;
	
	fprintf(fa,"\t<rect x='%d' y='%d' width='%d' height='%d' stroke='#%x' fill='#%x'>\n\t</rect>\n", xpoz, ypoz, xmeret, ymeret, szegely, kitoltes);
	
	fprintf(fa,"</svg>");
	fclose(fa);
	printf("\nOsztálypénz!\n");
	return 0;
}
