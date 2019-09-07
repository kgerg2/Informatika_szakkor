#include <stdio.h>
#include <time.h>

int main(){
	int i, width=1200, height=400, db=10000, osszdb;
	int tabla[db][6];
	time_t most;
	struct tm *tm;
	most = time(NULL);
	tm = localtime(&most);
	FILE *be;
	be = fopen("bekapcs.txt", "r");
	i = 0;
	while(!feof(be)){
		fscanf(be, "%d. %d. %d. %d:%d:%d\n", &tabla[i][0], &tabla[i][1], &tabla[i][2], &tabla[i][3], &tabla[i][4], &tabla[i][5]);
		i++;
	}
	osszdb = i;
	if(i>=db-2){
		printf("FIGYELEM!\n\tTúl sok adat, kérem töröljön!\n");
	} else if(i>db){
		printf("HIBA!\n\tTúl sok adat!\n");
	}
	
	fclose(be);
	FILE *fa;
	fa = fopen("proba.svg", "w");
	fprintf(fa, "<svg width='%d' height='%d' xmlns='http://www.w3.org/2000/svg' version='1.1'>\n", width, height);
	fprintf(fa, "\t<rect x='0' y='0' width='%d' height='100' stroke='#AA3333' fill='red'>\n", width);
	fprintf(fa, "\t</rect>\n");
	fprintf(fa, "\t<text x='%d' y='50' font-family='sans-serif' font-size='40px' fill='black'>\n\t\tBejelentkezések\n\t</text>\n", width/2-170);
	fprintf(fa, "\t<text x='25' y='75' font-family='sans-serif' font-size='15px' fill='black'>\n\t\t   Legutóbbi bejelentkezés ");
	if(tm->tm_mday==tabla[osszdb-1][2]){
		fprintf(fa, "ma %d óra %d perckor.", tabla[osszdb-1][3], tabla[osszdb-1][4]);
	} else if(tm->tm_mday==tabla[osszdb-1][2]-1){
		fprintf(fa, "tegnap %d óra %d perckor.", tabla[osszdb-1][3], tabla[osszdb-1][4]);
	} else if(tm->tm_mday==tabla[osszdb-1][2]-2){
		fprintf(fa, "tegnapelőtt %d óra %d perckor.", tabla[osszdb-1][3], tabla[osszdb-1][4]);
	} else{
		fprintf(fa, "%d. hó %d. napján %d óra %d perckor.", tabla[osszdb-1][1], tabla[osszdb-1][2], tabla[osszdb-1][3], tabla[osszdb-1][4]);
	}
	fprintf(fa, "\n\t</text>\n");
	fprintf(fa, "</svg>");
	fclose(fa);
	return 0;
}
