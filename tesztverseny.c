#include <stdio.h>

struct versenyzo{
	char az[6];
	char val[15];
};

int main(){
	int i, versdb, azon;
	char helyes[15];
	struct versenyzo vers[500];
	FILE *be;
	printf("1. feladat:");
	be = fopen("valaszok.txt", "r");
	fscanf(be, "%s\n", helyes);
	versdb = 0;
	while(!feof(be) && versdb<500){
		fscanf(be, "%s %s\n", vers[versdb].az, vers[versdb].val);
		//printf("%s %d ", vers[versdb].az, versdb);
		versdb++;
	}
	fclose(be);
	/*printf("%s\n", helyes);
	for(i=0;i<versdb;i++){
		printf("%s %s\n", vers[i].az, vers[i].val);
	}*/
	
	printf("Az adatok beolvasása\n\n");
	printf("2. feladat: A vetélkedőn %d versenyző indult\n\n", versdb);
	printf("3. feladat: A versenyző azonosítója = ");
	scanf("%s", azon);
	printf("%s ");
	return 0;
}
