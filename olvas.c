#include <stdio.h>

int main(){
	int i, db=10000;
	int tabla[db][6];
	FILE *fa;
	fa = fopen("bekapcs.txt", "r");
	i = 0;
	while(!feof(fa)){
		fscanf(fa, "%d. %d. %d. %d:%d:%d\n", &tabla[i][0], &tabla[i][1], &tabla[i][2], &tabla[i][3], &tabla[i][4], &tabla[i][5]);
		i++;
	}
	if(i>=db-2){
		printf("FIGYELEM!\n\tTúl sok adat, kérem töröljön!\n");
	} else if(i>db){
		printf("HIBA!\n\tTúl sok adat!\n");
	}
	
	fclose(fa);
	return 0;
}
