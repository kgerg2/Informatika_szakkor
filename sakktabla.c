#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
int xpoz, ypoz, meret, lapw, laph, korx, kory, ido, korxr, koryr;
	
	printf("Add meg, hogy mekkora legyen a sakktábla: ");
	scanf("%d", &meret);
	
	lapw = meret*50+20;
	laph = meret*50+20;
	
	FILE *fa;
	
	fa = fopen("sakktabla.svg", "w");
	fprintf(fa, "<svg width='%d' height='%d' xmlns='http://www.w3.org/2000/svg' version='1.1'>\n", lapw, laph);
	
	// Sakktábla
	for(ypoz=10;ypoz<=laph-50;ypoz=ypoz+100){
		for(xpoz=10;xpoz<=lapw-50;xpoz=xpoz+100){
			fprintf(fa,"\t<rect x='%d' y='%d' width='50' height='50' stroke='black' fill='black'>\n\t</rect>\n", xpoz, ypoz);
		}
	}
	for(ypoz=60;ypoz<=laph-50;ypoz=ypoz+100){
		for(xpoz=60;xpoz<=lapw-50;xpoz=xpoz+100){
			fprintf(fa,"\t<rect x='%d' y='%d' width='50' height='50' stroke='black' fill='black'>\n\t</rect>\n", xpoz, ypoz);
		}
	}
	
	//Kör
	fprintf(fa,"<circle cx='35' cy='35' r='20' stroke='' fill=''>\n\t<animate \n\t attributeName='fill'\n\t attributeType='XML'\n\t from='' to='red'\n\t begin='1s' dur='1s'\n\t fill='freeze'\n\t />\n");
	
	//Kör mozgatása
	srand((unsigned int) time(NULL));
	
	korxr = 35;
	koryr = 35;
	
	for(ido=3;ido<=meret*2+1;ido=ido+2){
		
		korx = rand()%meret*50+35;
		kory = rand()%meret*50+35;
		
		fprintf(fa,"\t<animate \n\t attributeName='cx'\n\t attributeType='XML'\n\t from='%d' to='%d'\n\t begin='%ds' dur='1s'\n\t fill='freeze'\n\t />\n\t<animate \n\t attributeName='cy'\n\t attributeType='XML'\n\t from='%d' to='%d'\n\t begin='%ds' dur='1s'\n\t fill='freeze'\n\t />\n", korxr, korx, ido, koryr, kory, ido);
		
		korxr = korx;
		koryr = kory;
	}
	
	//Vége
	fprintf(fa,"</circle>\n</svg>");
	fclose(fa);
	
	return 0;
}
