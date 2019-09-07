#include <stdio.h>

int main(){
    int i, db, csere, max, min, poz;
    scanf("%d", &db);
    char dns[db];
    int szam[db], kis[db], nagy[db];
    scanf("%s", dns);
    for(i=0;i<db;i++){
		if(dns[i]=='A'){
			szam[i] = 1;
			kis[i] = 1;
			nagy[i] = 1;
		}
		if(dns[i]=='C'){
			szam[i] = 2;
			kis[i] = 2;
			nagy[i] = 2;
		}
		if(dns[i]=='G'){
			szam[i] = 3;
			kis[i] = 3;
			nagy[i] = 3;
		}
		if(dns[i]=='T'){
			szam[i] = 4;
			kis[i] = 4;
			nagy[i] = 4;
		}
	}
	
	//Nagyobb
	i = db-1;
	while(szam[i]>szam[i+1] && i<=0){
		i--;
	}
	csere = i;
	min = 5;
	for(i=csere+1;i<db;i++){
		if(szam[i]<min && szam[i]>szam[csere]){
			min = szam[i];
			poz = i;
		}
	}
	szam[poz] = nagy[csere];
	nagy[csere] = min;
	for(i=csere+1;i<db;i++){
		max = -1;
		for(i=csere+1;i<db;i++){
			if(max==-1 && szam[i]!=0){
				max = i;
			} else if(max<szam[i]){
				max = i;
			}
		}
		nagy[i] = max;
	}
	for(i=0;i<db;i++){
		printf("%d", nagy[i]);
	}
    return 0;
}
