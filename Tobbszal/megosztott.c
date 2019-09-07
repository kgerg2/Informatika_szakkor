#include <stdio.h>
//#include <unistd.h>
//#include <sys/ipc.h>
//#include <sys/types.h>
#include <sys/shm.h>

int main(int argc, char *argv[]){
	key_t kulcs;
	int siker;
	kulcs = ftok(argv[0], 1); /** -1, ha sikertelen */
	siker = shmget(kulcs, 1024, IPC_CREAT/IPC_EXCL);
	printf("kulcs = %d\n", kulcs);
	if(siker==-1){
		printf("Nem sikerült.\n");
	} else{
		printf("Sikerült! \n");
	}
	return 0;
}
