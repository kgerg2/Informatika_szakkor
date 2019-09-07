#include <stdio.h>

struct sor{
	int ora;
	int perc;
	int mp;
	char rsz[7];
};

int valto(int ora, int perc, int mp){
	return 3600*ora+60*perc+mp;
}

int illesztes(char a[7], char b[7]){
	int i, vissza;
	vissza = 1;
	for(i=0;i<7;i++){
		if(!(a[i]=='*' || a[i]==b[i])){
			vissza = 0;
		}
	}
	return vissza;
}

int main(){
	struct sor lista[1000];
	char minta[7];
	int i, hossz, mido, elozoora, b, k, m, maxido, maxpoz;//Alsó porzíció
	maxido = 0;
	i = 0;
	b = 0;
	k = 0;
	m = 0;
	FILE *fa;
	fa = fopen("jarmu.txt", "r");
	while(!feof(fa)){
		fscanf(fa, "%d %d %d %7s\n", &lista[i].ora, &lista[i].perc, &lista[i].mp, lista[i].rsz);
		i++;
	}
	hossz = i;
	fclose(fa);
	/*for(i=0;i<hossz;i++){
		printf("%d\n", lista[i].rsz);
	}*/
	//2. feladat
	mido = lista[hossz-1].ora-lista[0].ora+1;
	printf("2. feladat:\n\nLegalább %d órát dolgoztak.\n", mido);
	//3. feladat
	elozoora = lista[0].ora-1;
	printf("\n3. feladat:\n\n");
	for(i=0;i<hossz;i++){
		if(elozoora<lista[i].ora){
			printf("%d óra: %s\n", lista[i].ora, lista[i].rsz);
		}
		elozoora = lista[i].ora;
	}
	//4. feladat
	for(i=0;i<hossz;i++){
		if(lista[i].rsz[0] == 'B'){
			b++;
		} else if(lista[i].rsz[0] == 'K'){
			k++;
		} else if(lista[i].rsz[0] == 'M'){
			m++;
		}
	}
	printf("\n4. feladat\n\nAutóbusz: %d db\nKamion: %d db\nMotor: %d db\nSzemélygépkocsi: %d db\n", b, k, m, hossz-b-k-m);
	//5. feladat
	for(i=0;i<hossz-1;i++){
		if(valto(lista[i+1].ora, lista[i+1].perc, lista[i+1].mp)-valto(lista[i].ora, lista[i].perc, lista[i].mp)>maxido){
			maxido = valto(lista[i+1].ora, lista[i+1].perc, lista[i+1].mp)-valto(lista[i].ora, lista[i].perc, lista[i].mp);
			maxpoz = i;
		}
	}
	printf("\n5. feladat\n\n%d:%d:%d - %d:%d:%d\n",
	lista[maxpoz].ora, lista[maxpoz].perc, lista[maxpoz].mp, lista[maxpoz+1].ora, lista[maxpoz+1].perc, lista[maxpoz+1].mp);
	//6. feladat
	printf("\n6. feladat\n\nKérem a rendszám mintáját: ");
	scanf("%s", minta);
	for(i=0;i<hossz;i++){
		if(illesztes(minta, lista[i].rsz)==1){
			printf("%s\n", lista[i].rsz);
		}
	}
	return 0;
}
