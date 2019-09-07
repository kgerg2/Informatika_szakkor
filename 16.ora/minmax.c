#include <stdio.h>

int szamlalo;
int sorozat(int be){
	szamlalo++;
	if(be%2==0){
		return sorozat(be/2);
	} else if(be==1){
		return 1;
	} else{
		return sorozat(3*be+1);
	}
}

int main(){
	int i, fel, al, min, max, minkezd, maxkezd;
	min = 0;
	max = 0;
	szamlalo = 0;
	printf("Add meg a felső határt: ");
	scanf("%d", &fel);
	printf("Add meg az alsó határt: ");
	scanf("%d", &al);
	for(i=al;i<=fel;i++){
		sorozat(i);
		if(szamlalo>max){
			max = szamlalo;
			maxkezd = i;
		}
		if(min==0 || szamlalo<min){
			min = szamlalo;
			minkezd = i;
		}
		szamlalo = 0;
	}
	printf("A legrövidebb sorozat %d tagú %d-től kezdve.\nA leghosszabb sorozat %d tagú %d-től kezdve.\n", min, minkezd, max, maxkezd);
	return 0;
}
