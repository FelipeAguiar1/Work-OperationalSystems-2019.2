#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

int ProcDir(char* palavra, char* diretorio) {
	struct dirent **namelist; //Porque 2 ** ?
   	int n = scandir(diretorio, &namelist, NULL, alphasort); //alphasort é uma função, assim como scandir
   	//printf("%d\n", n);
   	while (n--) {
		//printf("%s\n", namelist[n]->d_name);
		if (strcmp(namelist[n]->d_name, palavra)==0) {
			return 1;
		}
		free(namelist[n]);
   	}
   	free(namelist); //Queria entender como funciona o free
   	return 0;
}

int Menu() {
	int operacao;

	printf("OPERAÇÕES DISPONIVEIS:\n");
	printf("PWD [1] / CD [2] / LS [3] / MORE [4] / GREP [5] \n");
	printf("Digite a operação: ");
	scanf("%d", &operacao);

	return operacao;
}

void MostrarDir(char *dir) {
	if ( fork()==0 ) execlp("/bin/ls", "/bin/ls", dir, NULL) ;
    	else {
	    	sleep(1) ;  /* espera o fim de ls para executar o printf() */
	    	//printf ("Eu sou o pai e finalmente posso continuar\n") ;
	    }
   // exit(0);
}

void MostrarArq(char* dir, char* arq) {
	int op = ProcDir(arq, dir);

	if (op==1) {
		if ( fork()==0 ) execl("/bin/more", "more", arq, NULL);
	    	else {
		    	sleep(1) ;  /* espera o fim de ls para executar o printf() */
		    	//printf ("Eu sou o pai e finalmente posso continuar\n") ;
		    }
	} else {
		printf("Arquivo não existe no diretorio\n");
	}
}

int main() {
	DIR* diretorio;
	int verifica = 1;
	char dir[100] = "/home/felipeaguiar/Documentos";
	diretorio = opendir(dir);
	int operacao;
	char *op = (char*)malloc(100*sizeof(char));

	while (verifica==1) {
		operacao = Menu();
		switch(operacao) {
			case 1:
				printf("\n");
				printf("Diretorio atual: %s\n", dir);
				printf("\n");
			break;

			case 2:
				printf("cd ");
				scanf("%s", op);
				int proc = ProcDir(op, dir);
				if (proc==1) {
					strcat(op, "/");
					strcat(dir, op);
					printf("\n");
					printf("Diretorio atual: %s\n", dir);
				}
			break;

			case 3:
				MostrarDir(dir);
			break;

			case 4:
				printf("more ");
				scanf("%s", op);
				MostrarArq(dir, op);
			break;
		}
		printf("DESEJA CONTINUAR: SIM [1] / NÃO [Qualquer tecla] \n");
    	scanf("%d", &verifica);
	}
}
