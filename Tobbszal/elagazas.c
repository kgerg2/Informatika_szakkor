#include <stdio.h>
#include <unistd.h>

int main(){ 
	int i=0;
	int id; /** 0, ha ő a gyerek, a gyerek PID-je, ha ő a szülő. */
	printf("%d\n", i);
	id = CreateProcess();
	//printf("%d\n", id);
	if(id==0){
		printf("\nGyerek vagyok, a PID-em %d\n", getpid());
		while(i<10){
			printf("%d\t", i);
			i++;
		}
	} else{
		printf("\nSzülő vagyok, a gyerek PID-je: %d, a sajátom %d\n", id, getpid());
		while(i<11){
			printf("%d\t", i);
			i++;
		}
	}
	return 0;
}
/** processz (folyamat) azonosító (PID) (0-65535)
 * szülő viszi tovább, gyerek újat kap */
