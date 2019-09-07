#include <stdio.h>
#include <stdlib.h>

int hossz, kezd;

int keres(int elo, int (*ls)[2]){
    ls[elo][1] = 0;
    if(ls[elo][0]-1==kezd || ls[ls[elo][0]-1][1]==0){
        kezd = ls[elo][0]-1;
        return 1;
    }
    return keres(ls[elo][0]-1, ls)+1;
}

int keres2(int elo, int (*ls)[2]){
    ls[elo][1] = 0;
    if(ls[elo][0]-1==kezd/* || ls[ls[elo][0]-1][1]==0*/){
        printf("%d\n", elo+1);
        return 1;
    }
    printf("%d ", elo+1);
    return keres2(ls[elo][0]-1, ls)+1;
}

int main(){
    int i, j, db, max;
    scanf("%d", &db);
    int ls[db][2];
    for(i=0;i<db;i++){
        ls[i][1] = -1;
    }
    for(i=0;i<db;i++){
        scanf("%d", &ls[i][0]);
    }
    for(i=0;i<db;i++){
        kezd = i;
        if(ls[i][1]==-1){
            ls[i][1] = keres(i, ls);
            for(i=0;i<db;i++){
                ls[i][1] = -1;
            }
            ls[kezd][1] = keres(kezd, ls);
            for(j=0;j<db;j++){
                if(ls[j][1]==0){
                    ls[j][1] = ls[kezd][1];
                }
            }
        }/*
        for(j=0;j<db;j++){
            printf("\t%d\n", ls[j][1]);
        }*/
    }
    /*for(i=0;i<db;i++){
        printf("%d\n", ls[i][1]);
    }*/
    max = db-1;
    for(i=db-1;i>=0;i--){
        if(ls[i][1]>=ls[max][1]){
            max = i;
        }
    }
    printf("%d\n", ls[max][1]);
    kezd = max;
    keres2(kezd, ls);
    /*for(i=0;i<db;i++){
        if(ls[i][1]==max){
            printf("%d ", i+1);
        }
    }*/
    /*printf("Hello world!\n");*/
    return 0;
}
