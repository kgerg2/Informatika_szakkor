#include <stdio.h>

double gyok(double a){
	double elo;
	while(a!=elo){
		elo = a;
		a = 0.5*(elo+2/elo);
	}
	return a;
}

int prim_e(int a){
	int i=3;
	if(a==2 || a==3){
		return 1;
	}
	if(a%2==0){
		return 0;
	}
	while(a%i!=0 && i<gyok(a)){
		i += 2;
	}
	if(a%i==0){
		return 0;
	}
	return 1;
}

int main(){
	int i;
	FILE *be;
	be = fopen("1_feladat_input.txt", "r");
	
	fclose(be);
	return 0;
}
