#include <stdio.h>

int lista[200][200], ikeres, jkeres;

int vakond(int x, int y){
	int a, b, c, d;
	a = 0;
	b = 0;
	c = 0;
	d = 0;
	lista[x][y] = 2;
	if(lista[x-1][y]==0){
		a = vakond(x-1, y);
	}
	if(lista[x+1][y]==0){
		b = vakond(x+1, y);
	}
	if(lista[x][y-1]==0){
		c = vakond(x, y-1);
	}
	if(lista[x][y+1]==0){
		d = vakond(x, y+1);
	}
	if(x==ikeres && y==jkeres){
		lista[x][y] = 3;
		return 1;
	}else if(a==1 || b==1 || c==1 || d==1){
		lista[x][y] = 3;
		return 1;
	} else{
		return 0;
	}
}

int main(){
	int ihossz, jhossz, i, j, ibejarat, jbejarat, iplusz, jplusz;
	char dl;
	FILE *fa, *ki;
	i = 0;
	jhossz = 0;
	
	//Fájl olvasása
	
	fa = fopen("kicsi.csv", "r");
	while(!feof(fa)){
		j = 0;
		dl = ';';
		while(dl==';'){
			dl = 'x';
			fscanf(fa, "%d%c", &lista[i][j], &dl);
			j++;
		}
		i++;
		if(jhossz==0){
			jhossz = j;
		}
	}
	ihossz = i;
	ihossz--;
	fclose(fa);
	
	//Bejárat keresése
	
	for(i=0;i<ihossz;i++){
		if(lista[ihossz-1][i]==0){
			ibejarat = ihossz-1;
			jbejarat = i;
			iplusz = -1;
			jplusz = 0;
		}
		if(lista[i][0]==0){
			ibejarat = i;
			jbejarat = 0;
			iplusz = 0;
			jplusz = 1;
		}
		if(lista[i][jhossz-1]==0){
			ibejarat = i;
			jbejarat = jhossz-1;
			iplusz = 0;
			jplusz = -1;
		}
		if(lista[0][i]==0){
			ibejarat = 0;
			jbejarat = i;
			iplusz = 1;
			jplusz = 0;
		}
	}
	
	printf("Bejárat: %d. oszlop %d. sorában van.\n", ibejarat+1, jbejarat+1);
	
	//Út keresése
	
	printf("Add meg, hogy hányadik oszlop hányadik sorába szeretnél eljutni:\nOszlop: ");
	scanf("%d", &ikeres);
	printf("Sor: ");
	scanf("%d", &jkeres);
	ikeres--;
	jkeres--;
	
	lista[ibejarat][jbejarat] = 2;
	
	vakond(ibejarat+iplusz, jbejarat+jplusz);
	
	if(ikeres>ihossz || jkeres>jhossz){
		printf("A labirintuson kívüli helyet adtál meg.\n");
	} else if(lista[ikeres][jkeres]==1){
		printf("Az általad keresett hely fal.\n");
	} else if(lista[ikeres][jkeres]==0){
		printf("Az általad keresett helyre nem lehet bejutni.\n");
	} else{
		printf("Az adott helyre vezető útvonalat megtekintheted az svg fájlban.\n");
		lista[ibejarat][jbejarat] = 3;
	}
	
	//Svg fájl írása
	
	ki = fopen("labirintus.svg","w");
	fprintf(ki, "<svg width='%d' height='%d' xmlns='http://www.w3.org/2000/svg' version='1.1'>\n", 10*ihossz, 10*jhossz);
	for(i=0;i<ihossz;i++){
		for(j=0;j<jhossz;j++){
			if(lista[i][j]==0){
				fprintf(ki, "\t<rect x='%d' y='%d' width='10' height='10' stroke='white' fill='white' />\n", 10*i, 10*j);
			} else if(lista[i][j]==1){
				fprintf(ki, "\t<rect x='%d' y='%d' width='10' height='10' stroke='black' fill='black' />\n", 10*i, 10*j);
			} else if(lista[i][j]==2){
				fprintf(ki, "\t<rect x='%d' y='%d' width='10' height='10' stroke='yellow' fill='yellow' />\n", 10*i, 10*j);
			} else if(lista[i][j]==3){
				fprintf(ki, "\t<rect x='%d' y='%d' width='10' height='10' stroke='red' fill='red' />\n", 10*i, 10*j);
			}
		}
	}
	fprintf(ki, "</svg>");
	fclose(ki);
	return 0;
}
