/*********************************************
* Fecha: 7/10/2025
* Autor: Andres Loreto Quiros
* Materia: Sistemas Operativos
* Tema: Duplicidad de procesos y caos en creación
**********************************************/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("#=> Inicio del proceso main o proceso principal <=#\n\n\n");

    int procesoID = fork();

    /* Proceso HIJO */
    if(procesoID == 0){
        printf("\t #==> Proceso Hijo recién Creado \n");
    } 
    /* Proceso PADRE */
    else {
        printf("\t #==> Proceso Padre \n");
    }

    printf("Imprimiendo .... \n");
    for(int i = 0; i < 5; i++){
        printf("\t\t == %d == \n", i);
    }

    printf("FIN .... \n");

    return 0;
}




