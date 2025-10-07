/*********************************************
* Fecha: 7/10/2025
* Autor: Andres Loreto Quiros
* Materia: Sistemas Operativos
* Tema: Función Fork, creación de procesos
**********************************************/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("#=> Inicio del proceso main o proceso principal <=#\n\n\n");

    int procesoID = fork();

    /* Proceso PADRE */
    if(procesoID > 0){
        printf("\t #==> Proceso Padre con ID %d \n", getpid());
    } 
    /* Proceso HIJO */
    else {
        printf("\t #==> Proceso Hijo con ID %d \n", getpid());
    }

    printf("A partir de aquí es el proceso main o proceso principal \n");

    return 0;
}


