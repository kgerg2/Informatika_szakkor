#include <stdio.h>

struct sorok{
	char lo[41];
	int pont;
	int loves;
};

int loertek(char sor[41]){
	int aktpont, ertek, i;
	aktpont = 20;
	ertek = 0;
	i = 0;
	while(sor[i]!='\0'){
		if(aktpont>0 && sor[i]=='-'){
			aktpont--;
		} else{
			ertek = ertek+aktpont;
		}
		i++;
	}
	return ertek;
}

int loves(char keres[41]){
	int i=0;
	while(keres[i]!='\0'){
		i++;
	}
	return i;
}

int main(){
	int i, j, hossz, maxlo, keres, talalat, hibatlan, maxhibatlan, sorrmax, helyezes;
	maxhibatlan = 0;
	hibatlan = 0;
	helyezes = 0;
	talalat = 0;
	sorrmax = 0;
	maxlo = 0;
	FILE *be;
	be = fopen("verseny.txt", "r");
	fscanf(be, "%d\n", &hossz);
	struct sorok lista[hossz];
	int sorrbe[hossz], sorrki[hossz+1];
	sorrki[0] = 0;
	
	//1. feladat
	
	hossz = 0;
	while(!feof(be)){
		fscanf(be, "%s\n", lista[hossz].lo);
		hossz++;
	}
	fclose(be);
	
	//2. feladat
	printf("2. feladat:\nAz egymast kovetoen tobbszor talalo versenyzok:");
	
	for(i=0;i<hossz;i++){
		j = 0;
		while(!(lista[i].lo[j]=='+' && lista[i].lo[j+1]=='+') && lista[i].lo[j+1]!='\0'){
			j++;
		}
		if(lista[i].lo[j+1]!='\0'){
			printf(" %d", i+1);
		}
	}
	
	//3. feladat
	printf("\n3. feladat:\n");
	
	for(i=0;i<hossz;i++){
		lista[i].loves = loves(lista[i].lo);
		if(lista[maxlo].loves<lista[i].loves){
			maxlo = i;
		}
	}
	printf("A legtobb lovest ledo versenyzo rajtszama: %d\n", maxlo+1);
	
	//4. feladat
	
	for(i=0;i<hossz;i++){
		lista[i].pont = loertek(lista[i].lo);
	}
	
	//5. feladat
	printf("5. feladat:\nAdjon meg egy rajtszamot! ");
	
	scanf("%d", &keres);
	keres--;
	printf("5a. feladat: Celt ero lovesek:");
	i = 0;
	while(lista[keres].lo[i]!='\0'){
		if(lista[keres].lo[i]=='+'){
			printf(" %d", i+1);
			talalat++;
			hibatlan++;
		} else{
			hibatlan = 0;
		}
		if(maxhibatlan<hibatlan){
			maxhibatlan = hibatlan;
		}
		i++;
	}
	printf("\n5b. feladat: Az eltalalt korongok szama: %d\n", talalat);
	printf("5c. feladat: A leghosszabb hibatlan sorozat hossza: %d\n", maxhibatlan);
	printf("5d. feladat: A versenyzo pontszama: %d\n", lista[keres].pont);
	
	//6. feladat
	
	FILE *ki;
	ki = fopen("sorrend.txt", "w");
	
	for(i=0;i<hossz;i++){
		sorrbe[i] = lista[i].pont;
	}
	for(i=0;i<hossz;i++){
		for(j=0;j<hossz;j++){
			if(sorrbe[j]>sorrbe[sorrmax]){
				sorrmax = j;
			}
		}
		sorrki[i+1] = sorrmax;
		sorrbe[sorrmax] = 0;
	}
	for(i=0;i<hossz;i++){
		if(lista[sorrki[i]].pont != lista[sorrki[i+1]].pont){
			helyezes++;
		}
		fprintf(ki, "%d\t%d\t%d\n", helyezes, sorrki[i+1]+1, lista[sorrki[i+1]].pont);
	}
	fclose(ki);
	return 0;
}
