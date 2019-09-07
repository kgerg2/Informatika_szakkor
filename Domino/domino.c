#include <stdio.h>

int hossz, lista[100000][2];

int rak(int sor, int kov, int szel[2]){
	int a=0, b=0, uj[2], jo = 1, c;
	if(kov>=hossz){
		return sor;
	}
	c = rak(sor, kov+1, szel);
	if(szel[0]==lista[kov][0]){
		uj[0] = lista[kov][1];
		uj[1] = szel[1];
		a = rak(sor+1, kov+1, uj);
	} else if(szel[0]==lista[kov][1]){
		uj[0] = lista[kov][0];
		uj[1] = szel[1];
		a = rak(sor+1, kov+1, uj);
	} else{
		jo = 0;
	}
	if(szel[0]!=szel[1] && szel[1]==lista[kov][0]){
		uj[1] = lista[kov][1];
		uj[0] = szel[0];
		b = rak(sor+1, kov+1, uj);
	} else if(szel[0]!=szel[1] && szel[1]==lista[kov][1]){
		uj[1] = lista[kov][0];
		uj[0] = szel[0];
		b = rak(sor+1, kov+1, uj);
	} else if(jo==0){
		return rak(sor, kov+1, szel);
	} else{
		if(a>c){
			return a;
		}
	}
	if(a>b && a<c){
		return a;
	} else if(b>c){
		return b;
	} else{
		return c;
	}
}

int main(){
	int i;
	FILE *be, *ki;
	be = fopen("domino.be", "r");
	fscanf(be, "%d\n", &hossz);
	i = 0;
	for(i=0;i<hossz;i++){
		fscanf(be, "%d %d\n", &lista[i][0], &lista[i][1]);
	}
	/*printf("%d\n", hossz);
	i = 0;
	while(i<hossz){
		printf("%d %d\n", lista[i][0], lista[i][1]);
		i++;
	}*/
	fclose(be);
	ki = fopen("domino.ki", "w");
	fprintf(ki, "%d", rak(1, 1, lista[0]));
	fclose(ki);	
	return 0;
}
