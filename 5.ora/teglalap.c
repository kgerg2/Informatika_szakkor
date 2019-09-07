#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){
	int xpoz, ypoz, xmeret, ymeret, szegely, kitoltes;
	
	FILE *fa;
	
	srand((unsigned int) time(NULL));
	
	fa = fopen("teglalap.svg", "w");
	fprintf(fa, "<svg width='300' height='200' xmlns='http://www.w3.org/2000/svg' version='1.1'>\n");
	xpoz = random()%300;
	ypoz = random()%200;
	xmeret = random()%(300-xpoz);
	ymeret = random()%(200-ypoz);
	szegely = random()%0xFFFFFF;
	kitoltes = random()%0xFFFFFF;
	
	fprintf(fa,"\t<rect x='%d' y='%d' width='%d' height='%d' stroke='#%x' fill='#%x'>\n\t</rect>\n", xpoz, ypoz, xmeret, ymeret, szegely, kitoltes);
	
	fprintf(fa,"</svg>");
	fclose(fa);
	printf("\nOsztálypénz!\n");
	return 0;
}
