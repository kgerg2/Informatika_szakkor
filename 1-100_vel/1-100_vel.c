#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main (){
	int szam[100], i, j, jo, uj, szinek[100];
	char szin[4][6]; /** zöld, kék, piros, fekete */
	FILE *fa;
	srand((unsigned int) time(NULL));
	strcpy(szin[0], "green");
	strcpy(szin[1], "blue");
	strcpy(szin[2], "red");
	strcpy(szin[3], "black");
	
	for(i=0;i<100;i++){
		jo = 0;
		while(jo==0){
			jo = 1;
			uj = rand()%100;
			for(j=0;j<i;j++){
				if(szam[j]==uj){
					jo = 0;
				}
			}
		}
		szam[i] = uj;
	}
	/*for(i=0;i<100;i++){
		printf("%d ", szam[i]+1);
	}*/
	for(i=0;i<100;i++){
		szinek[i] = 0;
	}
	printf("szinezes kezdese\n");
	for(i=0;i<25;i++){
		do{
			uj = rand()%100;
		}while(szinek[uj]!=0);
		szinek[uj] = 1;
	}
	printf("1. szin kesz\n");
	for(i=0;i<25;i++){
		do{
			uj = rand()%100;
		}while(szinek[uj]!=0);
		szinek[uj] = 2;
	}
	printf("2. szin kesz\n");
	for(i=0;i<25;i++){
		do{
			uj = rand()%100;
		}while(szinek[uj]!=0);
		szinek[uj] = 3;
	}
	printf("3. szin kesz\n");	
	fa = fopen("szamok.svg", "w");
	fprintf(fa, "<svg width='100' height='2100' xmlns='http://www.w3.org/2000/svg' version='1.1'>\n");
	for(i=0;i<100;i++){
		fprintf(fa, "\t<text x='5' y='%d' font-family='sans-serif' font-size='15px' fill='black'>\n\t\t%d.\n\t</text>\n ", 20*i+20, i+1);
		fprintf(fa, "\t<text x='33' y='%d' font-family='sans-serif' font-size='20px' font-style='bald' fill='%s'>\n\t\t%d\n\t</text>\n ", 20*i+20, szin[szinek[i]], szam[i]+1);
	}
	fprintf(fa, "</svg>");
	fclose(fa);
	system("szamok.svg");
	return 0;
}
