#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, j, vendb, esdb, max, tanudb, tanutlan;
    scanf("%d %d", &vendb, &esdb);
    int ido[vendb][2], es[esdb], tanu[esdb];
    for(i=0;i<vendb;i++){
        scanf("%d %d", &ido[i][0], &ido[i][1]);
    }
    for(i=0;i<esdb-1;i++){
        tanu[i] = -2;
        scanf("%d ", &es[i]);
    }
    scanf("%d", &es[esdb-1]);
    tanudb = 0;
    tanutlan = 0;
    i = 0;
    while(i<esdb){
        /*printf("%d\n", i);*/
        max = -1;
        for(j=0;j<vendb;j++){
            if(ido[j][0]<=es[i] && ido[j][1]>=es[i] && (ido[j][1]>=ido[max][1] || max==-1)){
                max = j;
            }
        }
        /*printf("%d. esemeny %d-kor, %d. tanu %d-tol %d-ig\n", i+1, es[i], max+1, ido[max][0], ido[max][1]);*/
        /*for(j=0;j<esdb;j++){
            if(max==tanu[j]){
                max = -1;
            }
        }*/
        tanu[i] = max;
        if(max!=-1){
            tanudb++;
            while(ido[max][1]>=es[i+1] && i+1<esdb){
                i++;
            }
        } else{
            tanutlan++;
        }
        i++;
    }
    /*for(i=0;i<esdb;i++){
        printf("%d. %d\n", i, tanu[i]);
    }*/
    printf("%d\n%d\n", esdb-tanutlan, tanudb);
    j = 0;
    for(i=0;i<esdb;i++){
        if(tanu[i]>=0){
            j++;
            if(j==tanudb){
                printf("%d\n" , tanu[i]+1);
                return 0;
            } else{
                printf("%d ", tanu[i]+1);
            }
        }
    }
    return 0;
}
