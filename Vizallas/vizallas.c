#include <stdio.h>

struct lista{
	int h;
	char ho[11];
	int nap;
};

int main(){
	int i, j, k, l, honapok[12], max[2], maxviz;
	char honap[12][12];
	struct lista viz[365];
	FILE *va, *ho, *svg;
	
	va = fopen("adatok.csv", "r");
	for(i=0;i<365;i++){
		fscanf(va, "%d;%d\n", &j, &viz[i].h);
		if(i+1!=j){
			printf("HIBA (beolv.)\n");
		}
	}
	fclose(va);
	
	ho = fopen("honapok.csv", "r");
	for(i=0;i<12;i++){
		j = 0;
		while(honap[i][j-1]!=';'){
			fscanf(ho, "%c", &honap[i][j]);
			j++;
		}
		honap[i][j-1] = '\0';
		fscanf(ho, "%d\n", &honapok[i]);
	}
	fclose(ho);
	
	j = 0;
	for(i=0;i<12;i++){
		l = 1;
		while(honapok[i]>=l){
			viz[j].nap = l;
			l++;
			for(k=0;k<11;k++){
				viz[j].ho[k] = honap[i][k];
			}
			j++;
		}
	}
	
	//2.2. feladat (l - min)
	maxviz = 0;
	l = 0;
	for(i=1;i<365;i++){
		if(viz[maxviz].h<viz[i].h){
			maxviz = i;
		}
		if(viz[l].h>viz[i].h){
			l = i;
		}
	}
	printf("2.2. feladat\nA legmagasabb vízállás: %d cm, %d. nap, %s %d.\nA legalacsonyabb vízállás: %d cm, %d. nap, %s %d.\n", viz[maxviz].h, maxviz+1, viz[maxviz].ho, viz[maxviz].nap, viz[l].h, l+1, viz[l].ho, viz[l].nap);
	
	//2.3. feladat (k - kezd; l - vég)
	k = 0;
	l = 0;
	for(i=1;i<365;i++){
		if(viz[i].h==viz[i-1].h){
			l = i;
		} else{
			k = i;
			l = i;
		}
		if(l-k>max[1]-max[0]){
			max[0] = k;
			max[1] = l;
		}
	}
	printf("2.3. feladat\nA leghosszabb stagnálás %d nap: %s %d (%d. nap)- %s %d (%d. nap).\n", max[1]-max[0]+1, viz[max[0]].ho, viz[max[0]].nap, max[0], viz[max[1]].ho, viz[max[1]].nap, max[1]);
	
	//2.4. feladat (j - árvízveszély)
	j = 0;
	for(i=0;i<360;i++){
		if(viz[i].h>=520){
			j++;
		}
	}
	printf("2.4. feladat\nEbben az évben %d árvízveszélyes nap volt.\n", j);
	
	//2.5. feladat (k - kezd; l - vég)
	k = 0;
	l = 0;
	for(i=1;i<365;i++){
		if(viz[i].h>=520 && 520<=viz[i-1].h){
			l = i;
		} else{
			k = i;
			l = i;
		}
		if(l-k>max[1]-max[0]){
			max[0] = k;
			max[1] = l;
		}
	}
	printf("2.3. feladat\nA leghosszabb árvízveszélyes időszak %d nap: %s %d (%d. nap)- %s %d (%d. nap).\n", max[1]-max[0]+1, viz[max[0]].ho, viz[max[0]].nap, max[0], viz[max[1]].ho, viz[max[1]].nap, max[1]);
	
	//2.6. feladat
	maxviz = viz[maxviz].h/10;
	maxviz = maxviz+3;
	maxviz = maxviz*10;
	svg = fopen("vizallas.svg", "w");
	fprintf(svg, "<svg width='730' height='%d' xmlns='http://www.w3.org/2000/svg' version='1.1'>\n", maxviz);	
	for(i=0;i<365;i++){
		fprintf(svg, "\t<line x1='%d' y1='%d' x2='%d' y2='%d' stroke='blue' stroke-width='2'>\n\t</line>\n", i*2, maxviz, i*2, maxviz-viz[i].h);
	}
	fprintf(svg, "</svg>");
	fclose(svg);
	return 0;
}
