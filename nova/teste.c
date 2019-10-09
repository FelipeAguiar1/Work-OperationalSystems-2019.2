#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int ProcDir(char* palavra, DIR* diretorio) {
    char* item_diretorio;

    if (!diretorio ) {       
        perror( "opendir" );
    }   
    
    item_diretorio = (char*) readdir( diretorio );  
    
    while( item_diretorio ) {
        if (palavra==item_diretorio) {
            return 1;
            break;
        }       
        item_diretorio = (char*) readdir( diretorio );  
    }   

    return 0;
    closedir( diretorio );   
}

char* MudaDir(char *palavra, DIR* diretorio) {
    char *copia = palavra;
    int op;
    op = ProcDir(copia, diretorio);
    if (op==1) {
     //   char *texto = (char*)malloc(100);
        char *exe = (char*)malloc(100);

    //    printf("Digite algo: ");
    //    scanf("%[^\n]", texto);

        for (int i = 3; i<strlen(palavra); i++) {
            exe[i-3] = palavra[i];
        }

        printf("diretorio atual %s\n", exe);

        return exe;    
    }

    return NULL;
}

void ListarDir(char* palavra) {
    printf("entrou\n");
    DIR* diretorio;
    struct dirent* item_diretorio;
    diretorio = opendir(palavra);

    if (!diretorio ) {
        perror( "opendir" );
    }
    
    item_diretorio = readdir( diretorio );  
    
    while( item_diretorio ) {       
        printf( "Item = %s\n", item_diretorio->d_name );        
        item_diretorio = readdir( diretorio );  
    }   
    
    closedir( diretorio );    
}

int main() {   
    char *operacao = (char*)malloc(100); 
    DIR* diretorio; 
    struct dirent* item_diretorio;
    char *teste = "/";
    char* teste1 = (char*)malloc(100);
    diretorio = opendir(teste);

    printf("Diretorio atual %s\n", teste);
    printf("Digite a operacao: ");
    scanf("%s", operacao);
    int op = strcmp(operacao, "ls");
    printf("numero %d\n", op);

    if (op==0) {
        printf("foi\n");
        ListarDir(teste);
    } else {
        printf("Diretorio: ");
        scanf("%s", teste1);
        teste1 = MudaDir(teste1, diretorio);
        strcat(teste, teste1);
    }

/*
    if (!diretorio ) {       
        perror( "opendir" );        
        return( -1 );
    }   
    
    item_diretorio = readdir( diretorio );  
    
    while( item_diretorio ) {       
        printf( "Item = %s\n", item_diretorio->d_name );        
        item_diretorio = readdir( diretorio );  
    }   
    
    closedir( diretorio );  
    return( 0 );
    */
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int main(void) {
    char *teste = (char*)malloc(100);
    char *aux = (char*)malloc(100);
    DIR *dir;
    struct dirent *lsdir;
    
   // strcpy(teste, ":/");
    
   // printf("Digite algo ");
    // scanf("%s", aux);
    
   // strcat(teste, aux);
   // strcat(teste, "/");

    dir = opendir(":/");

    /* print all the files and directories within directory */
/*
    while ( ( lsdir = readdir(dir) ) != NULL )
    {
        printf ("%s\n", lsdir->d_name);
    }

    closedir(dir);

    return 0;
}
*/
