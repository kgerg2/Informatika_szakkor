#include <stdio.h>
#include <stdlib.h>

int var[1000][2], ut[10000][2], latogatott[1000], latdb, teldb, vardb, utdb;

int var_e(int mi){
    int i;
    for(i=0;i<vardb;i++){
        if(var[i][0]==mi){
            return 1;
        }
    }
    return 0;
}

int lat(int mit){
    int i;
    for(i=0;i<utdb;i++){
        if(mit==latogatott[i]){
            return 1;
        }
    }
    return 0;
}

int utker(int hol){
    int i, utak[teldb-1][2], utakdb=0, kap, min, enlat; /**< utak[i][0] -> hova; utak[i][1] -> milyen hosszan */
    if(var_e(hol)==1){
        /*printf(" (%d) Vissza: %d (varos)\n", hol, hol);*/
        return hol;
    } else{
        latogatott[latdb] = hol;
        enlat = latdb;
        latdb++;
    }
    for(i=0;i<utdb;i++){
        if(ut[i][0]==hol && lat(ut[i][1])==0){
            /*printf(" (%d)  - %d\n", hol, ut[i][1]);*/
            kap = utker(ut[i][1]);
            if(kap>0){
                utak[utakdb][0] = kap%10000;
                utak[utakdb][1] = kap/10000+1;
                /*printf(" (%d) Uj: %d-be %d lepesbol (%d. ut).\n", hol, utak[utakdb][0], utak[utakdb][1], utakdb);*/
                utakdb++;
            }
        }
        if(ut[i][1]==hol && lat(ut[i][0])==0){
            /*printf(" (%d)  - %d\n", hol, ut[i][0]);*/
            kap = utker(ut[i][0]);
            if(kap>0){
                utak[utakdb][0] = kap%10000;
                utak[utakdb][1] = kap/10000+1;
                /*printf(" (%d) Uj: %d-be %d lepesbol (%d. ut).\n", hol, utak[utakdb][0], utak[utakdb][1], utakdb);*/
                utakdb++;
            }
        }
        /*if(utak[utakdb-1][1]==1){
            printf(" (%d) Vissza: utak[%d-1][0] (%d) + 10000 = %d\n", hol, utakdb, utak[utakdb-1][0], utak[utakdb-1][0]+10000);
            return utak[utakdb-1][0]+10000;
        }*/
    }
    /*printf(" (%d) osszes ut felderitve.\n");*/
    if(utakdb==0){
        /*printf(" (%d), Vissza: 0\n", hol);*/
        return 0;
    }
    min = 0;
    if(utakdb>1){
        for(i=0;i<utakdb;i++){
            if(utak[i][1]<utak[min][1] || (utak[i][1]==utak[min][1] && utak[i][0]<utak[min][0])){
                min = i;
            }
        }
    }
    latogatott[enlat] = 0;
    /*printf(" (%d) Vissza: utak[%d][0] (%d) + utak[%d][1] (%d) x 10000 = %d\n", hol, min, utak[min][0], min, utak[min][1], utak[min][0]+utak[min][1]*10000);*/
    return utak[min][0]+utak[min][1]*10000;
}

int main(){
    int i, j, uttal;
    for(i=0;i<1000;i++){
        var[i][0] = 0;
        var[i][1] = 0;
    }
    for(i=0;i<10000;i++){
        ut[i][0] = 0;
        ut[i][1] = 0;
    }
    scanf("%d %d %d", &teldb, &vardb, &utdb);
    /*for(i=0;i<vardb;i++){
        var[i][1] = 1;
    }*/
    scanf("%d", &var[0][0]);
    if(vardb>1){
        for(i=1;i<vardb;i++){
            scanf(" %d", &var[i][0]);
        }
    }
    for(i=0;i<utdb;i++){
        scanf("%d %d", &ut[i][0], &ut[i][1]);
    }
    for(i=1;i<=teldb;i++){
        for(j=0;j<1000;j++){
            latogatott[j] = 0;
        }
        /*printf("%d. telepules:\n", i);*/
        if(var_e(i)==0){
            uttal = utker(i);
            j = 0;
            while(var[j][0]!=uttal%10000 && j<=vardb){
                j++;
            }
            var[j][1]++;
            /*printf("%d. varosba (eddig ide %d db).\n", uttal%10000, var[j][1]);*/
        }
    }
    for(i=0;i<vardb;i++){
        /*printf("%d. %d-s varos: ", i, var[i][0]);*/
        printf("%d\n", var[i][1]+1);
    }
    return 0;
}
