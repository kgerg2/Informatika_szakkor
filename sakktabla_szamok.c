#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	int a, b, db;
	printf("Add meg, hogy milyen nagy legyen a sakktábla: ");
	scanf("%d", &db);
	
	for(a=0;a<db;a++){
		if(a%2==0){
			printf(" ");
		}
		for(b=0;b<db;b++){
			if(b%2==0){
				printf("x");
			} else {
				printf(" ");
			}
		}
		printf("\n");
	}
	
	int xpoz, ypoz, meret, lapw, laph;
	
	printf("Add meg, hogy mekkora legyen a sakktábla: ");
	scanf("%d", &meret);
	
	lapw = meret*50+20;
	laph = meret*50+20;
	
	FILE *fa;
	
	srand((unsigned int) time(NULL));
	
	fa = fopen("sakktabla.svg", "w");
	fprintf(fa, "<svg width='%d' height='%d' xmlns='http://www.w3.org/2000/svg' version='1.1'>\n", lapw, laph);
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
	fprintf(fa,"</svg>");
	fclose(fa);
	return 0;
}
