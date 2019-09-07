#include <stdio.h>
#include <stdlib.h>

int ikul(int i1[4], int i2[4]){
    return 60*(i2[2]-i1[2])+i2[3]-i1[3];
}

int main(){
    int i, j, k, pozdb, eszldb, van, ido;
    scanf("%d %d", &pozdb, &eszldb);
    int eszl[eszldb][4];
    for(i=0;i<eszldb;i++){
        scanf("%d %d %d %d", &eszl[i][0], &eszl[i][1], &eszl[i][2], &eszl[i][3]);
    }
    for(i=1;i<pozdb;i++){
        van = 0;
        ido = -1;
        for(j=0;j<eszldb;j++){
            for(k=j;k<eszldb;k++){
                if(eszl[j][0]==eszl[k][0]){
                    /*printf(" (%d) %d=%d & %d=%d & (%d=0 || %d<%d)\n", eszl[j][0], eszl[j][1], i, eszl[k][1], i+1, van, ikul(eszl[j], eszl[k]), ido);*/
                }
                if(eszl[j][0]==eszl[k][0] && eszl[j][1]==i && eszl[k][1]==i+1 && (van==0 || ikul(eszl[j], eszl[k])<ido)){
                    van = eszl[j][0];
                    ido = ikul(eszl[j], eszl[k]);
                    /*printf("rsz: %d, ido: %d\n", van, ido);*/
                }
            }
        }
        if(i==pozdb-1){
            printf("%d\n", van);
        } else{
            printf("%d ", van);
        }
    }
    for(i=1;i<pozdb;i++){
        van = 0;
        ido = -1;
        for(j=0;j<eszldb;j++){
            for(k=j;k<eszldb;k++){
                if(eszl[j][0]==eszl[k][0]){
                    /*printf(" (%d) %d=%d & %d=%d & (%d=0 || %d<%d)\n", eszl[j][0], eszl[j][1], i+1, eszl[k][1], i, van, ikul(eszl[j], eszl[k]), ido);*/
                }
                if(eszl[j][0]==eszl[k][0] && eszl[j][1]==i+1 && eszl[k][1]==i && (van==0 || ikul(eszl[j], eszl[k])<ido)){
                    van = eszl[j][0];
                    ido = ikul(eszl[j], eszl[k]);
                    /*printf("rsz: %d, ido: %d\n", van, ido);*/
                }
            }
        }
        if(i==pozdb-1){
            printf("%d\n", van);
        } else{
            printf("%d ", van);
        }
    }
    return 0;
}
