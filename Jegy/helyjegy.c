#include <stdio.h>

struct utasok{
	int hely;
	int fel;
	int le;
};

int kerek(int a){
	if(a%5<2){
		return a-a%5;
	} else{
		return a-a%5+5;
	}
}

int utdij(int dij, int fel, int le){
	if((le-fel)%10==0){
		return (le-fel)/10*dij;
	} else{
		return ((le-fel)/10+1)*dij;
	}
}

int main(){
	int i, osszdb, hossz, dij, bev=0, ut, ut_fel=0, ut_le=0, uj, uldb, j;
	FILE *be;
	be = fopen("eladott.txt", "r");
	fscanf(be, "%d %d %d\n", &osszdb, &hossz, &dij);
	struct utasok jegy[osszdb];
	int megall[osszdb*2];
	for(i=0;i<osszdb;i++){
		fscanf(be, "%d %d %d\n", &jegy[i].hely, &jegy[i].fel, &jegy[i].le);
	}
	fclose(be);
	/*for(i=0;i<osszdb;i++){
		printf("%2d. utas: ülés: %3d, fel: %3d, le: %3d\n", i+1, jegy[i].hely, jegy[i].fel, jegy[i].le);
	}*/
	
	//2. feladat
	printf("2. feladat: %d. utas: ülés: %3d, táv: %3d\n", osszdb, jegy[osszdb-1].hely, jegy[osszdb-1].le-jegy[osszdb-1].fel);
	
	//3. feladat
	printf("3. feladat: teljes távon utazók: ");
	for(i=0;i<osszdb;i++){
		if(jegy[i].fel == 0 && jegy[i].le == hossz){
			printf("%d. utas, ", i+1);
		}
	}
	
	//4. feladat
	printf("\n4. feladat:");
	for(i=0;i<osszdb;i++){
		bev = bev+kerek(utdij(dij, jegy[i].fel, jegy[i].le));
	}
	printf(" bevétel: %d Ft.\n", bev);
	
	//5. feladat
	ut = 0;
	for(i=0;i<osszdb;i++){
		if(jegy[i].fel>ut && jegy[i].fel!=hossz){
			ut = jegy[i].fel;
		}
		if(jegy[i].le>ut && jegy[i].le!=hossz){
			ut = jegy[i].le;
		}
	}
	for(i=0;i<osszdb;i++){
		if(jegy[i].fel==ut){
			ut_fel++;
		}
		if(jegy[i].le==ut){
			ut_le++;
		}
	}
	printf("5. feladat: utolsó előtti megállónál (%d km) %d felszálló, %d leszálló\n", ut, ut_fel, ut_le);
	
	//6. feladat
	for(i=0;i<osszdb*2;i++){
		megall[i] = -1;
		if(i%2==0){
			uj = jegy[i/2].fel;
		} else{
			uj = jegy[i/2].le;
		}
		j = 0;
		while(megall[j]!=-1 && j<osszdb*2 && uj!=megall[j]){
			j++;
		}
		if(megall[j]==-1){
			megall[j] = uj;
		}
	}
	i = 0;
	while(megall[i]!=-1){
		i++;
	}
	printf("6. feladat: összesen %d megálló van.\n", i);
	
	//7. feladat
	printf("7. feladat: hányadik km utasait írjam ki: ");
	scanf("%d", &ut);
	while(ut>hossz || ut<0){
		printf("Kérem, egy legfeljebb %d nagyságú természetes számot adjon meg: ", hossz);
		scanf("%d", &ut);
	}
	uldb = 0;
	for(i=0;i<osszdb;i++){
		if(jegy[i].hely>uldb){
			uldb = jegy[i].hely;
		}
	}
	//printf("%d", uldb);
	FILE *ki;
	ki = fopen("kihol.txt", "w");
	for(i=0;i<uldb;i++){
		fprintf(ki, "%d. ülés: ", i+1);
		j = 0;
		while(!(jegy[j].fel<=ut && jegy[j].le>ut && jegy[j].hely==i) && j<osszdb){
			j++;
		}
		if(j<osszdb){
			fprintf(ki, "%d. utas\n", j+1);
		} else{
			fprintf(ki, "üres\n");
		}
	}
	fclose(ki);
	printf("Eredmény: ld. a \"kihol.txt\" fájlban.\n");
	return 0;
}
