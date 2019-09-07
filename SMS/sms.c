#include <stdio.h>

struct sms {
	int ora;
	int perc;
	int tsz;//Kénytelen voltam számként tárolni, mert különben nem tudtam volna dolgozni vele a 6. és 8. feladatban.
	char sz[101];
	int szh;
};

int main(){
	struct sms lista[101];
	int i, j, hossz, maxhossz, minhossz, maxhely, minhely, szhkat[5], orak[24], marad, maxido, elozo, kov, mintel, tsz[101];
	char olv;
	for(i=0;i<100;i++){
		lista[i].szh = 0;
	}
	i = 0;
	elozo = 0;
	maxido = 0;
	maxhossz = 0;
	minhossz = 100;
	mintel = 1000000000;
	
	//1. feladat
	
	FILE *fa;
	fa = fopen("sms.txt", "r");
	fscanf(fa, "%d\n", &hossz);
	hossz = 0;
	while(!feof(fa)){
		fscanf(fa, "%d %d %d\n", &lista[hossz].ora, &lista[hossz].perc, &lista[hossz].tsz);
		for(j=0;j<100;j++){//Máshogy kellett beolvasnom, hogy megtudjam a szöveg hosszát (szh).
			fscanf(fa, "%c^\n", &olv);
			lista[hossz].sz[i] = olv;
			lista[hossz].szh++;
			i++;
			if(olv=='\n'){
				j = 99;
			}
		}
		i = 0;
		hossz++;
	}
	fclose(fa);
	
	//2. feladat
	printf("2. feladat:\n");
	
	if(hossz>10){
		printf("%s\n", lista[9].sz);
	} else{
		printf("%s\n", lista[hossz-2].sz);
	}
	
	//3. feladat
	printf("3. feladat:\n");
	
	for(i=0;i<hossz;i++){
		if(maxhossz<lista[i].szh){
			maxhossz = lista[i].szh;
			maxhely = i;
		}
		if(minhossz>lista[i].szh){
			minhossz = lista[i].szh;
			minhely = i;
		}
	}
	printf("A leghosszabb SMS:\n\t%d %d %09d\n\t%s\n", lista[maxhely].ora, lista[maxhely].perc, lista[maxhely].tsz, lista[maxhely].sz);
	printf("A legrovidebb SMS:\n\t%d %d %09d\n\t%s\n", lista[minhely].ora, lista[minhely].perc, lista[minhely].tsz, lista[minhely].sz);
	
	//4. feladat
	printf("4. feladat:\n");
	
	for(i=0;i<hossz;i++){
		if(lista[i].szh>=1 && lista[i].szh<=20){
			szhkat[0]++;
		} else if(lista[i].szh>=21 && lista[i].szh<=40){
			szhkat[1]++;
		} else if(lista[i].szh>=41 && lista[i].szh<=60){
			szhkat[2]++;
		} else if(lista[i].szh>=61 && lista[i].szh<=80){
			szhkat[3]++;
		} else if(lista[i].szh>=81 && lista[i].szh<=100){
			szhkat[4]++;
		}
	}
	printf("0-20: %d\n21-40: %d\n41-60: %d\n61-80: %d\n81-100: %d\n", szhkat[0], szhkat[1], szhkat[2], szhkat[3], szhkat[4]);
	
	//5. feladat
	printf("\n5. feladat:\n");
	
	for(i=0;i<hossz;i++){
		orak[lista[i].ora]++;
	}
	for(i=1;i<=24;i++){
		if(orak[i]>10){
			marad = marad+orak[i]-10;
		}
	}
	printf("%d uzenet van pluszban.\n", marad);
	
	//6. feladat
	printf("\n6. feladat:\n");
	
	for(i=0;i<hossz;i++){
		if(lista[i].tsz==123456789 && elozo == 0){
			elozo = lista[i].ora*60+lista[i].perc;
		} else if(lista[i].tsz==123456789){
			kov = elozo;
			elozo = lista[i].ora*60+lista[i].perc;
			if(elozo-kov>maxido){
				maxido = elozo-kov;
			}
		}
	}
	if(maxido==0){
		printf("Nincs elegendo uzenet.\n");
	} else{
		printf("%d ora %d perc.\n", maxido/60, maxido%60);
	}
	
	//7. feladat
	printf("\n7. feladat:\n");
	
	printf("Mikor erkezett az uzenet (ora perc): ");
	scanf("%d %d", &lista[hossz].ora, &lista[hossz].perc);
	printf("Milyen telefonszamrol kuldtek: ");
	scanf("%d", &lista[hossz].tsz);
	printf("Mi az uzenet szovege: ");
	scanf("%[^\n]", lista[hossz].sz);
	//printf("\n%d %d %09d\n", lista[hossz].ora, lista[hossz].perc, lista[hossz].tsz);
	//printf("%s\n", lista[i].sz);
	
	//8. feladat
	
	FILE *ki;
	ki = fopen("smski.txt", "w");
	
	for(i=0;i<hossz+1;i++){
		tsz[i] = lista[i].tsz;
	}
	for(j=0;j<hossz+1;j++){
		for(i=0;i<hossz+1;i++){
			if(mintel>tsz[i]){
				mintel = tsz[i];
			}
		}
		if(mintel!=1000000000){
			fprintf(ki, "%09d\n", mintel);
		}
		for(i=0;i<hossz+1;i++){
			if(lista[i].tsz==mintel && tsz[i]!=1000000000){
				fprintf(ki, "%d %d %s", lista[i].ora, lista[i].perc, lista[i].sz);
				if(lista[i].sz[lista[i].szh-1]!='\n'){
					fprintf(ki, "\n");
				}
				tsz[i] = 1000000000;
			}
		}
		mintel = 1000000000;
	}
	
	fclose(ki);
	return 0;
}
