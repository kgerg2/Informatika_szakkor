#include <stdio.h>

int main(){
	int db, lista[1000], max, poz, maxpoz;
	db = 0;
	max = 0;
	FILE *fa;
	fa = fopen("lista.txt","r");
	while(!feof(fa)){
		fscanf(fa, "%d\n", &lista[db]);
		db = db+1;
	}
	/*for(i=0;i<db;i++){
		printf("%d\n", lista[i]);
	}*/
	fclose(fa);
	for(poz=0;poz<db-1;poz++){
		if(max<lista[poz]+lista[poz+1]){
			max = lista[poz]+lista[poz+1];
			maxpoz = poz;
		}
	}
	printf("A legnagyobb összeg a %d, a %d. és %d. elem összege.\n", max, maxpoz, maxpoz+1);
	return 0;
}
