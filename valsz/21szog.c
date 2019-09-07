#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DB 100000

int kul(int a, int b, int mod){
	int eredm;
	eredm = a-b;
	while(eredm<0){
		eredm+=mod;
	}
	while(eredm>=mod){
		eredm-=mod;
	}
	/*if(mod-eredm<eredm){
		eredm = mod-eredm;
	}*/
	return eredm;
}

int teszt(){
	int a, b, c, max;
	a = rand()%21;
	b = rand()%21;
	c = rand()%21;
	if(kul(a, b, 21)>kul(a, c, 21) && kul(a, b, 21)>kul(b, c, 21)){
		
	} else if(kul(a, c, 21)>kul(b, c, 21)){
		
	} else{
		
	}
}

int main(){
	int i, jo;
	srand((unsigned int) time(NULL));
	for(i=0;i<DB;i++){
		jo += teszt();
	}
	return 0;
}
