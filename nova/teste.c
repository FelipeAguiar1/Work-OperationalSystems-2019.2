#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(void) {
    
    char *teste = (char*)malloc(100);
    char *aux = (char*)malloc(100);
    DIR *dir;
    struct dirent *lsdir;
    
    strcpy(teste, "c:/");
    
    scanf("%s", aux);
    
    strcat(teste, aux);
    strcat(teste, "/");

    dir = opendir(teste);

    /* print all the files and directories within directory */
    while ( ( lsdir = readdir(dir) ) != NULL )
    {
        printf ("%s\n", lsdir->d_name);
    }

    closedir(dir);

    return 0;

}
