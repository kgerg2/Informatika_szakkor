#include <stdio.h>
#include <stdlib.h>

int kerdb, utdb, ker[1000], kereszt;

int tartalmaz(int *mi, int mekkora, int mit){
    for(;mekkora>0;mekkora--){
        if(mi[mekkora]==mit){
            return 1;
        }
    }
    return 0;
}

int keres(int poz, int elo, int (*ut)[2], int *bejart, int bejartdb){
    /*printf(" (%d) kezd\n", poz);*/
    int i;
    if(bejart[0]==poz){
        /*printf(" (%d) kor vege\n", poz);*/
        kereszt = 1;
        ker[0] = poz;
        return 1;
    }
    /*for(i=0;i<bejartdb;i++){
        if(bejart[i]==poz){
            printf(" (%d) korbeert, nincs kor\n", poz);
            return 0;
        }
    }*/
    bejart[bejartdb] = poz;
    bejartdb++;
    for(i=0;i<utdb;i++){
        if(ut[i][0] == poz && ut[i][1] != elo && tartalmaz(bejart, bejartdb-1, ut[i][1])==0){
            /*printf(" (%d) tovabb %d-be\n", poz, ut[i][1]);*/
            if(keres(ut[i][1], poz, ut, bejart, bejartdb)==1){
                /*printf(" (%d) van kor\n", poz);*/
                ker[kereszt] = poz;
                kereszt++;
                return 1;
            }
        }
        if(ut[i][1] == poz && ut[i][0] != elo && tartalmaz(bejart, bejartdb-1, ut[i][0])==0){
            /*printf(" (%d) tovabb %d-be\n", poz, ut[i][0]);*/
            if(keres(ut[i][0], poz, ut, bejart, bejartdb)==1){
                /*printf(" (%d) van kor\n", poz);*/
                ker[kereszt] = poz;
                kereszt++;
                return 1;
            }
        }
    }
    /*if(van==0){
        printf(" (%d) nincs kor\n", poz);
        return 0;
    }
    printf(" (%d) van kor\n", poz);
    scanf("%d", &i);
    return 1;*/
    /*printf(" (%d) nincs kor\n", poz);*/
    return 0;
}

int main(){
    int i, j, jokerdb;
    scanf("%d %d", &kerdb, &utdb);
    int ut[utdb][2], bejart[kerdb], keresztezodes[kerdb];
    for(i=0;i<utdb;i++){
        scanf("%d %d", &ut[i][0], &ut[i][1]);
    }
    for(i=0;i<kerdb;i++){
        keresztezodes[i] = -1;
    }
    jokerdb = 0;
    for(i=0;i<kerdb;i++){
        /*printf("%d:\n", i);*/
        if(keresztezodes[i]==-1){
            keresztezodes[i] = keres(i+1, -1, ut, bejart, 0);
            if(keresztezodes[i]==1){
                /*printf("A kor tartalma: ");*/
                for(j=0;j<kereszt;j++){
                    /*printf("%d ", ker[j]);*/
                    keresztezodes[ker[j]-1] = 1;
                }
                /*printf("\n");*/
            }
        }
        if(keresztezodes[i]==0){
            jokerdb++;
        }
    }
    printf("%d\n", jokerdb);
    utdb = 0;
    for(i=0;i<kerdb;i++){
        if(keresztezodes[i]==0){
            utdb++;
            if(utdb==jokerdb){
                printf("%d", i+1);
            } else{
                printf("%d ", i+1);
            }
        }
    }
    printf("\n");
    return 0;
}
