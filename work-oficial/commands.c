#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include "utils.h"

// FUNÇÃO PARA PROCURAR DIRETORIO INFORMADO PELO USER
int ProcDir(char* palavra, char* diretorio) {
	struct dirent **namelist;
   	int n = scandir(diretorio, &namelist, NULL, alphasort);
   	while (n--) {
		if (strcmp(namelist[n]->d_name, palavra)==0 || strcmp(namelist[n]->d_name, palavra)==10) {
			return 1;
		}
		free(namelist[n]);
   	}
   	free(namelist);
   	return 0;
}
// FUNÇÃO DO LS, LISTA ARQUIVOS DO DIRETORIO ATUAL
void MostrarDir(char *dir) {
	if ( fork()==0 ) execlp("/bin/ls", "/bin/ls", dir, NULL) ;
    	else {
	    	sleep(1);
	    }
}

void MostrarArq(char* dir, char* arq) {
	int op = ProcDir(arq, dir);

	if (op==1) {
		if ( fork()==0 ) execl("/bin/more", "more", arq, NULL);
	    	else {
		    	sleep(1);
		    }
	} else {
		printf("Arquivo não existe no diretorio\n");
	}
}


