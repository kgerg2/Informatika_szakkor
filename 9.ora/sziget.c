#include <stdio.h>

int main(){
	int pil, tenger, szig, w, db, i, j, maxviz, maxvizpoz, tav;
	db = 0;
	w = 0;
	maxviz = 0;
	maxvizpoz = 0;
	printf("Add meg, hogy hány pillért használhatok:");
	scanf("%d", &pil);
	FILE *fb;
	FILE *fa;
	fb = fopen("szigetek.svg","w");
	fa = fopen("szigetek.txt","r");
	
	//Kép rajzolása
	
	while(!feof(fa)){
		fscanf(fa, "%d %d\n", &szig, &tenger);
		w = w+szig+tenger;
		db = db+1;
	}
	fprintf(fb,"<svg width='%d' height='50' xmlns='http://www.w3.org/2000/svg' version='1.1'>\n", w/2);
	fprintf(fb,"\t<rect x='0' y='25' width='%d' height='25' stroke='blue' fill='blue'>\n\t</rect>\n\t<rect x='0' y='0' width='%d' height='3' stroke='black' fill='black'>\n\t</rect>\n", w/2, w/2);
	db = db-1;
	int viz[db];
	int sziget[db];
	int rajz[pil+db];
	int oszt[db];
	for(i=0;i<=db;i++){
		oszt[i] = 1;
	}
	w = 0;
	db = 0;
	fclose(fa);
	
	//Szigetek rajzolása
	
	fa = fopen("szigetek.txt","r");
	while(!feof(fa)){
		fscanf(fa, "%d %d\n", &szig, &tenger);
		fprintf(fb,"\t<rect x='%d' y='0' width='%d' height='50' stroke='green' fill='green'>\n\t</rect>\n", w/2, szig/2);
		w = w+szig+tenger;
		viz[db] = tenger;
		sziget[db] = szig;
		db = db+1;
	}
	
	//Pillérek elhelyezése
	
	for(i=0;i<pil;i++){
		for(j=0;j<db;j++){
			if((double)viz[j]/oszt[j]>maxviz){
				maxviz = (double)viz[j]/oszt[j];
				maxvizpoz = j;
			}
		}
		oszt[maxvizpoz] = oszt[maxvizpoz]+1;
		maxviz = 0;
	}
	
	//Pillérek rajzolása
	
	for(i=0;i<db;i++){
		if(maxviz<viz[i]/oszt[i]){
			maxviz = viz[i]/oszt[i];
		}
		if(i!=0){
			tav = tav+sziget[i]+viz[i-1];
		} else{
			tav = sziget[i];
		}
		if(oszt[i]>1){
			for(j=1;j<oszt[i];j++){
				rajz[i] = tav+(double)viz[i]/oszt[i]*j;
				fprintf(fb, "\t<rect x='%d' y='0' width='6' height='50' stroke='black' fill='grey'/>\n", rajz[i]/2-3);
			}
		}
	}
	fprintf(fb,"\n</svg>");
	printf("\nA leghosszabb hídszakasz %d m %d pillért használva.\n", maxviz, pil);
	fclose(fa);
	fclose(fb);
	return 0;
}
