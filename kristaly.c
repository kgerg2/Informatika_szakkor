#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct poz{
	int x;
	int y;
};

int tavolsag(struct poz p, struct poz q){
	int a, b;
	if(p.x-q.x<0){
		a = q.x-p.x;
	} else {
		a = p.x-q.x;
	}
	if(p.y-q.y<0){
		b = q.y-p.y;
	} else {
		b = p.y-q.y;
	}
	if(a>b){
		return a;
	} else{
		return b;
	}
	//return a+b;
	
}

int main(){
	int i, j, kezd, tav, k, mintav, minszin;
	mintav = 501;
	printf("Hány helyről kezdődjön: ");
	scanf("%d", &kezd);
	struct poz sz[kezd], temp;
	int szin[kezd];
	srand((unsigned int) time(NULL));
	for(i=0;i<kezd;i++){
		szin[i] = rand()%0xFFFFFF;
		sz[i].x = rand()%300;
		sz[i].y = rand()%200;
	}
	FILE *fa;
	fa = fopen("kristaly.svg", "w");
	fprintf(fa, "<svg width='600' height='400' xmlns='http://www.w3.org/2000/svg' version='1.1'>\n");
	for(i=0;i<300;i++){
		for(j=0;j<200;j++){
			for(k=0;k<kezd;k++){
				temp.x = i;
				temp.y = j;
				tav = tavolsag(sz[k], temp);
				printf("\t%d\n", tav);
				if(tav<mintav){
					mintav = tav;
					minszin = k;
				}
			}
			printf("%d\n", mintav);
			fprintf(fa, "\t<rect x='%d' y='%d' width='2' height='2' stroke='white' fill='white'>\n", i*2, j*2);
			fprintf(fa, "\t<animate \n\t\tattributeName='fill'\n\t\tattributeType='XML'\n\t\tfrom='white' to='#%x'\n\t\tbegin='%dms' dur='500ms'\n\t\tfill='freeze'\n\t/>\n", szin[minszin], mintav*500);
			fprintf(fa, "\t<animate \n\t\tattributeName='stroke'\n\t\tattributeType='XML'\n\t\tfrom='white' to='#%x'\n\t\tbegin='%dms' dur='500ms'\n\t\tfill='freeze'\n\t/>\n", szin[minszin], mintav*500);
			fprintf(fa, "\t</rect>\n");
			mintav = 501;
		}
	}
	fprintf(fa, "</svg>");
	fclose(fa);
	return 0;
}
