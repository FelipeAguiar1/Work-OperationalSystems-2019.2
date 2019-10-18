#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

int main() {
	DIR* diretorio; // VARIAVEL PARA ABRIR DIRETORIO
	int verifica = 0;
	char dir[100] = "/home/"; // VARIAVEL QUE FUNCIONA COMO DIRETORIO PRINCIPAL
	diretorio = opendir(dir); // FUNÇÃO DA BIBLIOTECA DIRENT PARA ABRIR DIRETORIO
	char* operacao = (char*)malloc(100);
	char* operacao_1 = (char*)malloc(100);
	char *op = (char*)malloc(100*sizeof(char));
	int proc;
	int teste;

	while (1) {
		//MENU PARA USER
		printf("OPERAÇÕES DISPONIVEIS:\n");
		printf("PWD [1] / CD [2] / LS [3] / MORE [4] / GREP [5] / EXIT\n");
		printf("Digite a operação: ");
		fgets(operacao, 100, stdin);

		//PESQUISA O QUE O USER DIGITOU
		if (strcmp(operacao, "exit")==10 || strcmp(operacao, "exit")==10) {
			break;
		}

		for (int i=0; i<strlen(operacao); i++) {
			if (operacao[i]==' ') {
				if (strcmp(operacao_1, "cd")==0 || strcmp(operacao_1, "cd")==10) {
					for (int j=0; j<strlen(operacao); j++) {
						op[j] = operacao[j+3];
					}
					teste = strlen(op) - 1;
					if (strcmp(op, "..")==0 || strcmp(op, "..")==10) {
						dir[teste] = '\0';
						for (int j=strlen(dir)-1; j>0; j--) {
							dir[j] = '\0';
							if (dir[j]=='/') {
								break;
							}
						}
					}
					if (op[teste]=='\n') {
						op[teste] = '\0';
					}
					verifica = 2;
					break;
				}
			}
			operacao_1[i] = operacao[i];

			if (strcmp(operacao, "pwd")==10 || strcmp(operacao, "pwd")==0) {
				verifica = 1;
			} else if (strcmp(operacao, "ls")==10 || strcmp(operacao, "ls")==0) {
				verifica = 3;
			}
		}
		// SWITCH PARA COMANDOS DO USER
		switch(verifica) {
			case 1: // COMANDO PWD
				printf("\n");
				printf("Diretorio atual: %s\n", dir);
				printf("\n");
				verifica = 0;
			break;

			case 2: // COMANDO CD
				if (strcmp(op, "..")==0 || strcmp(op, "..")==10) {
					verifica = 0;
					break;
				}
				proc = ProcDir(op, dir);
				if (proc==1) {
					strcat(op, "/");
					strcat(dir, op);
					printf("Diretorio atual: %s\n", dir);
				} else {
					printf("Diretorio inexistente!\n");
				}
				verifica = 0;
			break;

			case 3: // COMANDO LS
				MostrarDir(dir);
				verifica = 0;
			break;

			case 4:
				printf("CODIGO NÃO IMPLEMENTADO!");
				verifica = 0;
			break;

			case 5:
				printf("CODIGO NÃO IMPLEMENTADO!");
				verifica = 0;
			break;

			default:
				printf("COMANDO INVALIDO!\n");
			break;
		}
	}
}