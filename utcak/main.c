#include <stdio.h> /** korábbi megoldás lent */
#include <stdlib.h>

struct tabla{
    int x1;
    int y1;
    int x2;
    int y2;
};

int lehet_e(int a1, int b1, int a2, int b2, int *varos, struct tabla *tab, int tabl, int s, int o, int elore){
    int i;
    if(a2<0 || a1<0 || b1<0 || b2<0 || a2>=s || a1>=s || b1>=o || b2>=o){ /** kimegy a városból */
        return 0;
    }
    for(i=0;i<tabl;i++){ /** akadályozó tábla */
        if(a1==tab[i].x1 && b1==tab[i].y1 && a2==tab[i].x2 && b2==tab[i].y2){
            return 0;
        }
    }
    if(varos[o*a2+b2]!=0 && elore!=0){ /** már felderített */
        return 0;
    }
    return 1;
}

int main(){
    int i, j, sor, oszl, tabl, sx, sy, cx, cy, x1, y1, szint, jo_e;

    /** beolvasás */
    FILE *be;
    be = fopen("utcak.be", "r");
    fscanf(be, "%d %d %d\n", &sor, &oszl, &tabl);
	int varos[sor*oszl];
	struct tabla tab[tabl];
	for(i=0;i<sor;i++){
        for(j=0;j<oszl;j++){
            varos[i*oszl+j] = 0;
        }
	}
	for(i=0;i<tabl;i++){
        fscanf(be,"%d %d %d %d\n", &tab[i].x1, &tab[i].y1, &tab[i].x2, &tab[i].y2);
        tab[i].x1--; tab[i].y1--; tab[i].x2--; tab[i].y2--;
	}
	fscanf(be,"%d %d %d %d\n", &sx, &sy, &cx, &cy);
	sx--; sy--; cx--; cy--;
    fclose(be);

    /**  */
    varos[oszl*sx+sy] = 1;
    szint = 1;
    jo_e = 0;
    while(jo_e==0){
        jo_e = -1;
        for(i=0;i<sor*oszl && jo_e!=1;i++){
            if(varos[i]==szint){
                jo_e = 0;
                y1 = i%oszl;
                x1 = (i-y1)/oszl;
                if(lehet_e(x1, y1, x1+1, y1, varos, tab, tabl, sor, oszl, 1)==1){
                    if(cx==x1+1 && cy==y1){
                        jo_e = 1;
                    }
                    varos[oszl*(x1+1)+y1] = szint+1;
                }
                if(lehet_e(x1, y1, x1-1, y1, varos, tab, tabl, sor, oszl, 1)==1){
                    if(cx==x1-1 && cy==y1){
                        jo_e = 1;
                    }
                    varos[oszl*(x1-1)+y1] = szint+1;
                }
                if(lehet_e(x1, y1, x1, y1+1, varos, tab, tabl, sor, oszl, 1)==1){
                    if(cx==x1 && cy==y1+1){
                        jo_e = 1;
                    }
                    varos[oszl*x1+y1+1] = szint+1;
                }
                if(lehet_e(x1, y1, x1, y1-1, varos, tab, tabl, sor, oszl, 1)==1){
                    if(cx==x1 && cy==y1-1){
                        jo_e = 1;
                    }
                    varos[oszl*x1+y1-1] = szint+1;
                }
            }
        }
        szint++;
    }
    /*for(i=0;i<sor;i++){
        for(j=0;j<oszl;j++){
            printf("%d ", varos[i*oszl+j]);
        }
        printf("\n");
	}*/
    if(jo_e==-1){
        printf("Nincs ilyen útvonal.\n");
        return 0;
    }
    int ut[szint][3];
    x1 = cx;
    y1 = cy;
    for(i=szint-1;i>0;i--){
        ut[i][0] = x1;
        ut[i][1] = y1;
        if(varos[oszl*(x1+1)+y1]==i && lehet_e(x1+1, y1, x1, y1, varos, tab, tabl, sor, oszl, 0)==1){
            x1++;
            ut[i-1][3] = 'D';
        } else if(varos[oszl*(x1-1)+y1]==i && lehet_e(x1-1, y1, x1, y1, varos, tab, tabl, sor, oszl, 0)==1){
            x1--;
            ut[i-1][3] = 'E';
        } else if(varos[oszl*x1+y1+1]==i && lehet_e(x1, y1+1, x1, y1, varos, tab, tabl, sor, oszl, 0)==1){
            y1++;
            ut[i-1][3] = 'N';
        } else if(varos[oszl*x1+y1-1]==i && lehet_e(x1, y1-1, x1, y1, varos, tab, tabl, sor, oszl, 0)==1){
            y1--;
            ut[i-1][3] = 'K';
        } else{
            printf("HIBA\n");
        }
        if(i==1){
            ut[i-1][0] = x1;
            ut[i-1][1] = y1;
        }
    }
    printf("%d\n", szint-1);
    for(i=0;i<szint-1;i++){
        printf("%c", ut[i][3]);
    }
    return 0;
}
/*
struct tabla{
    int x1;
    int y1;
    int x2;
    int y2;
};

void verembe(char *verem, int *hossz, char lepes){
    verem[*hossz] = lepes;
    (*hossz)++;
}

char verembol(char *verem, int *hossz){
    (*hossz)--;
    return verem[*hossz+1];
}

int lehet_e(int a1, int b1, int a2, int b2, struct tabla *t, int tabl, char *verem, int vm, int s, int o){
    int i;
    if(a2<1 || a1<1 || b1<1 || b2<1 || a2>o || a1>s || b1>s || b2>o){
        return 0;
    }
    for(i=0;i<tabl;i++){
        if(a1==t[i].x1 && b1==t[i].y1 && a2==t[i].x2 && b2==t[i].y2){
            return 0;
        }
    }

}

int main(){
	int i, s, o, tabl, sx, sy, cx, cy, mv=0; /*< s -> sorok, o -> oszlopok, tabl -> táblák
	FILE *be, *ki;

	BEOLVASÁS
	be = fopen("utcak.be", "r");
	fscanf(be, "%d %d %d\n", &s, &o, &tabl);
	char verem[s*o];
	struct tabla t[tabl];
	for(i=0;i<t;i++){
        fscanf(be,"%d %d %d %d\n", &t[i].x1, &t[i].y1, &t[i].x2, &t[i].y2);
	}
	fscanf(be,"%d %d %d %d\n", &sx, &sy, &cx, &cy);
	fclose(be);

	return 0;
}
*/
