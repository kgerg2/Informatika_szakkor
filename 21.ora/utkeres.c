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

int eldb=0, cel, utvonal[100], kov_pont=0;
struct elek ellista[4950]; 

int utker(int hol, int honnan[100]){
	int jo=0, i, j=0, k, hova[99];
	if(hol==cel){
		utvonal[kov_pont] = hol;
		kov_pont++;
		return 1;
	}
	for(i=0;i<eldb;i++){
		if(ellista[i].k==hol){
			jo = 1;
			for(k=1;k<honnan[0]+1;k++){
				if(honnan[k]==ellista[i].v){
					jo = 0;
				}
			}
			if(jo==1){
				hova[j] = ellista[i].v;
				j++;
			}
		}
		if(ellista[i].v==hol){
			jo = 1;
			for(k=1;k<honnan[0]+1;k++){
				if(honnan[k]==ellista[i].k){
					jo = 0;
				}
			}
			if(jo==1){
				hova[j] = ellista[i].k;
				j++;
			}
		}
	}
	if(j==0){
		return 0;
	}
	i = 0;
	jo = 0;
	honnan[0]++;
	honnan[honnan[0]] = hol;
	while(jo==0 && i<j){
		jo = utker(hova[i], honnan);
		i++;
	}
	if(jo==0){
		return 0;
	} else{
		utvonal[kov_pont] = hol;
		kov_pont++;
		return 1;
	}
}

int main(){
	int i, j, csdb=0, maxcsucselpoz=0, indul, siker, utresz;
	struct csucs cslista[100];
	FILE *cs, *svg, *el;
	
	//Beolv.
	
	cs = fopen("csucsok.csv", "r");
	while(!feof(cs)){
		fscanf(cs, "%d;%d;%d\n", &cslista[csdb].ssz, &cslista[csdb].x, &cslista[csdb].y);
		csdb++;
	}
	fclose(cs);
	int csucsel[csdb];
	for(i=0;i<csdb;i++){
		csucsel[i] = 0;
	}
	el = fopen("elek.csv", "r");
	while(!feof(el)){
		fscanf(el, "%d;%d\n", &ellista[eldb].k, &ellista[eldb].v);
		eldb++;
	}
	fclose(el);
	
	//Legnagyobb kereszteződés
	
	for(i=0;i<eldb;i++){
		csucsel[ellista[i].k-1]++;
		csucsel[ellista[i].v-1]++;
	}
	for(i=0;i<csdb;i++){
		if(csucsel[i]>maxcsucselpoz){
			maxcsucselpoz = i;
		}
	}
	
	//Út keresése
	
	printf("Add meg, hogy honnan akarsz indulni: ");
	scanf("%d", &indul);
	printf("Add meg, hogy hova akarsz menni: ");
	scanf("%d", &cel);
	utvonal[0] = 0;
	siker = utker(indul, utvonal);
	if(siker==0){
		printf("Nem lehet ilyen utat találni.\n");
	} else{
		printf("Az utat keresd az svg-ben (pirossal).\n");
	}
	for(i=0;i<kov_pont;i++){
		printf("%d;", utvonal[i]);
	}
	
	//Rajz
	
	svg = fopen("graf.svg", "w");
	fprintf(svg, "<svg width='800' height='600' xmlns='http://www.w3.org/2000/svg' version='1.1'>\n");
	for(i=0;i<csdb;i++){
		if(i==maxcsucselpoz){
			fprintf(svg, "\t<circle cx='%d' cy='%d' r='10' stroke='black' fill='red'>\n\t</circle>\n", cslista[i].x, cslista[i].y);
		} else if(i+1==cel || i+1==indul){
			fprintf(svg, "\t<circle cx='%d' cy='%d' r='5' stroke='black' fill='red'>\n\t</circle>\n", cslista[i].x, cslista[i].y);
		} else{
			fprintf(svg, "\t<circle cx='%d' cy='%d' r='5' stroke='black' fill='black'>\n\t</circle>\n", cslista[i].x, cslista[i].y);
		}
	}
	for(i=0;i<eldb;i++){
		utresz = 0;
		for(j=0;j<kov_pont;j++){
			if((ellista[i].k==utvonal[j] && ellista[i].v==utvonal[j+1]) || (ellista[i].v==utvonal[j] && ellista[i].k==utvonal[j+1])){
				utresz = 1;
			}
		}
		if(utresz==1){
			fprintf(svg, "\t<line x1='%d' y1='%d' x2='%d' y2='%d' stroke='red' stroke-width='4'>\n\t</line>\n", cslista[ellista[i].k-1].x, cslista[ellista[i].k-1].y, cslista[ellista[i].v-1].x, cslista[ellista[i].v-1].y);
		} else{
			fprintf(svg, "\t<line x1='%d' y1='%d' x2='%d' y2='%d' stroke='black' stroke-width='2'>\n\t</line>\n", cslista[ellista[i].k-1].x, cslista[ellista[i].k-1].y, cslista[ellista[i].v-1].x, cslista[ellista[i].v-1].y);
		}
	}
	fprintf(svg, "</svg>");
	fclose(svg);
	return 0;
}
//Max él egy csúcsból -> piros
//2 sorszám között út 
