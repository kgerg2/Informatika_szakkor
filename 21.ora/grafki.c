#include <stdio.h>

struct csucs{
	int ssz;
	int x;
	int y;
};

struct elek{
	int k;
	int v;
};

int main(){
	int i, csdb=0, eldb=0;
	struct csucs cslista[100];
	struct elek ellista[4950]; 
	FILE *cs, *svg, *el;
	
	cs = fopen("csucsok.csv", "r");
	while(!feof(cs)){
		fscanf(cs, "%d;%d;%d\n", &cslista[csdb].ssz, &cslista[csdb].x, &cslista[csdb].y);
		csdb++;
	}
	fclose(cs);
	
	el = fopen("elek.csv", "r");
	while(!feof(el)){
		fscanf(el, "%d;%d\n", &ellista[eldb].k, &ellista[eldb].v);
		eldb++;
	}
	fclose(el);
	
	svg = fopen("graf.svg", "w");
	fprintf(svg, "<svg width='800' height='600' xmlns='http://www.w3.org/2000/svg' version='1.1'>\n");
	for(i=0;i<csdb;i++){
		fprintf(svg, "\t<circle cx='%d' cy='%d' r='5' stroke='black' fill='black'>\n\t</circle>\n", cslista[i].x, cslista[i].y);
	}
	for(i=0;i<eldb;i++){
		fprintf(svg, "\t<line x1='%d' y1='%d' x2='%d' y2='%d' stroke='black' stroke-width='2'>\n\t</line>\n", cslista[ellista[i].k-1].x, cslista[ellista[i].k-1].y, cslista[ellista[i].v-1].x, cslista[ellista[i].v-1].y);
	}
	fprintf(svg, "</svg>");
	fclose(svg);
	return 0;
}
//Max él egy csúcsból -> piros
//2 sorszám között út 
