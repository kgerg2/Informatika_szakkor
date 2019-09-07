#include <stdio.h>

int prim(int x){
	int i;
	for(i=2;i<=x/2;i++){
		if(x%i==0){
			return 0;
		}
	}
	return 1;
}

int main(){
	int i, j, primdb;
	double arany;
	FILE *fa;
	fa = fopen("hisztogram.svg", "w");
	
	fprintf(fa,"<svg width='1000' height='500' xmlns='http://www.w3.org/2000/svg' version='1.1'>\n");
	
	for(i=2;i<=10002;i=i+10){
		for(j=2;j<=i;j++){
			if(prim(j)==1){
				primdb++;
				//printf("\t%d\n", primdb);
			}
		}
		printf("%d\n", primdb);
		arany = ((double)i)/((double)primdb);
		fprintf(fa, "\t<rect x='%d' y='%f' width='1' height='%f' stroke='blue' fill='blue'>\n\t</rect>\n", (i-2)/10, 500-arany*50, arany*50);
		primdb = 0;
	}
	fprintf(fa, "</svg>");
	fclose(fa);
	return 0;
}
