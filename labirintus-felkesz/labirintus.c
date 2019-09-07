#include <stdio.h>
#include <unistd.h>
#define LABIRINT "labirintus.csv"           
#define WIDTH  160
#define HEIGHT 120
#define MERET 5

int l[HEIGHT][WIDTH], uthossz;

struct poz {
	int honnan; /** pont sorszáma */
	int x;
	int y;
	int rend; /** hozzá vezető út hossza (bbi, bbj-től) */
};

struct poz ut[WIDTH*HEIGHT/2];

int lehet_e(int x, int y, int h){ /** h = ut lista hossza */
	int i;
	if(x<0 || y<0 || x>=HEIGHT || y>= WIDTH){ /** nem része a labirintusnak */
		return 0;
	}
	if(l[x][y]==1){ /** fal */
		return 0;
	}
	for(i=0;i<h;i++){ /** már bejárt */
		if(ut[i].x == x && ut[i].y == y){
			return 0;
		}
	}
	return 1;
}

void keres(int x,int y){
	l[x][y]=2;
	if(l[x-1][y]==0){
		keres(x-1,y);
	} 
	if(l[x+1][y]==0){
		keres(x+1,y);
	}
	if(l[x][y-1]==0){
		keres(x,y-1);
	} 
	if(l[x][y+1]==0){
		keres(x,y+1);
	}
}

int utkeres(int x, int y, int cx, int cy){
	if(x==cx && y==cy){
		l[x][y] = 3;
		return 1;
	}
	l[x][y] = 4; /** sárga szín */
	int t1=0, t2=0, t3=0, t4=0;
	if(l[x-1][y]==2){
		t1 = utkeres(x-1, y, cx, cy);
		if(t1==1){
			l[x][y]=3;
			return 1;
		}
	} 
	if(l[x+1][y]==2){
		t2 = utkeres(x+1, y, cx, cy);
		if(t2==1){
			l[x][y]=3;
			return 1;
		}
	}
	if(l[x][y-1]==2){
		t3 = utkeres(x, y-1, cx, cy);
		if(t3==1){
			l[x][y]=3;
			return 1;
		}
	} 
	if(l[x][y+1]==2){
		t4 = utkeres(x, y+1, cx, cy);
		if(t4==1){
			l[x][y]=3;
			return 1;
		}
	}
	return 0;
}

int main() {
	int i, j, szin, bi, bj, bbi, bbj;
	FILE *svg, *csv;
	
	csv = fopen(LABIRINT,"r");
	for(i=0;i<HEIGHT;i=i+1){
		for(j=0;j<WIDTH;j=j+1){
			fscanf(csv,"%d;",&l[i][j]);
		}
	}
	fclose(csv);

	for(j=0;j<WIDTH;j++){
		if(l[0][j]==0){
			bi = 0;
			bj = j;
			bbi = 1;
			bbj = j;
		}
		if(l[HEIGHT-1][j]==0){
			bi = HEIGHT-1;
			bj = j;
			bbi = HEIGHT-2;
			bbj = j;
		}
	}
	for(i=0;i<HEIGHT;i++){
		if(l[i][0]==0){
			bi = i;
			bj = 0;
			bbi = i;
			bbj = 1;
		}
		if(l[i][WIDTH-1]==0){
			bi = i;
			bj = WIDTH-1;
			bbi = i;
			bbj = WIDTH-2;
		}
	}
	l[bi][bj]=-1;
	
	keres(bbi, bbj);
	
	/** Útkeresés */
	int cx, cy;
	
	printf("Adja meg a cél kordinátáit x,y alakban: ");
	scanf("%d, %d",&cx,&cy);
	if(l[cx][cy]!=2){
		printf("nem elérhető, fal vagy nem vezet ide út \n");
	} else {
		utkeres(bbi, bbj, cx, cy);
	}
	
	/** A legrövidebb út keresése */
	
	int hossz=1, vege;
	ut[0].honnan = -1;
	ut[0].x = bi;
	ut[0].y = bj;
	ut[0].rend = 0;
	i = 0;
	vege = 0;
	while(vege==0){
		vege = -1; /** Ha nincs i rendű pont, -1 marad, a ciklusnak vége lesz. */
		for(j = hossz-1;j>=0 && vege!=1 && ut[j].rend==i;j--){ /** csak az i rendű pontokat nézze (egymás mellettiek) */
			vege = 0;
			if(lehet_e(ut[j].x+1, ut[j].y, hossz)==1){
				ut[hossz].x = ut[j].x+1;
				ut[hossz].y = ut[j].y;
				ut[hossz].rend = i+1;
				ut[hossz].honnan = j;
				if(ut[hossz].x==cx && ut[hossz].y==cy){
					vege = 1;
				}
				hossz++; /** az if után kell csak növelni */
			}
			if(lehet_e(ut[j].x-1, ut[j].y, hossz)==1){
				ut[hossz].x = ut[j].x-1;
				ut[hossz].y = ut[j].y;
				ut[hossz].rend = i+1;
				ut[hossz].honnan = j;
				if(ut[hossz].x==cx && ut[hossz].y==cy){
					vege = 1;
				}
				hossz++;
			}
			if(lehet_e(ut[j].x, ut[j].y+1, hossz)==1){
				ut[hossz].x = ut[j].x;
				ut[hossz].y = ut[j].y+1;
				ut[hossz].rend = i+1;
				ut[hossz].honnan = j;
				if(ut[hossz].x==cx && ut[hossz].y==cy){
					vege = 1;
				}
				hossz++;
			}
			if(lehet_e(ut[j].x, ut[j].y-1, hossz)==1){
				ut[hossz].x = ut[j].x;
				ut[hossz].y = ut[j].y-1;
				ut[hossz].rend = i+1;
				ut[hossz].honnan = j;
				if(ut[hossz].x==cx && ut[hossz].y==cy){
					vege = 1;
				}
				hossz++;
			}
		}
		i++;
	}
	if(vege==1){ /** ha van út */
		j = hossz-1;
		while((ut[j].x != cx || ut[j].y != cy) && j>=0){ /** cél sorszámának keresése */
			j--;
		}
		while(ut[j].honnan!=-1){ /** útvonal pontjainak értékét 5-re állítja (zöld) */
			l[ut[j].x][ut[j].y] = 5;
			j = ut[j].honnan;
		}
		l[bi][bj] = 5; /** kezdőpont */
	}
	
	/** Rajzolás */
	
	svg = fopen("labirintus.svg","w");
	fprintf(svg,"<?xml version='1.0'?>\n");
	fprintf(svg,"<svg width='%d' height='%d' xmlns='http://www.w3.org/2000/svg' version='1.1' xmlns:xlink='http://www.w3.org/1999/xlink'>\n", WIDTH * MERET, HEIGHT * MERET);
	szin = 0xff0000;
	for(i=0;i<HEIGHT;i++){
		for(j=0;j<WIDTH;j++){
			if(l[i][j]==1){
				szin = 0x000000;
			}else if(l[i][j]==2 || l[i][j]==4){ /** ez is sárgát jelöl (56. sor, utkeres fv.) */
				szin = 0xffff00;
			}else if(l[i][j]==3){
				szin = 0xff0000;
			}else if(l[i][j]==5){
				szin = 0x00ff00;
			} else{
				szin = 0xffffff;
			}
			fprintf(svg,"<rect x='%d' y='%d' width='%d' height='%d' fill='#%06x' />\n",j*MERET ,i*MERET,MERET,MERET, szin);
		}
		
	}
	fprintf(svg,"</svg>\n");
	fclose(svg);
	return 0;
}
