/* Materia: Sistemas Operativos
* Tema: Comunicación entre procesos con PIPE y FORK
**********************************************/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h> // Para wait()

int main() {
    int fd[2]; // Arreglo con dos extremos: fd[0] lectura, fd[1] escritura
    pipe(fd);  // Crea el pipe

    printf("#=> Inicio del proceso main o proceso principal <=#\n\n");

    int pid = fork();

    if (pid > 0) {
        // ---- PROCESO PADRE ----
        close(fd[0]); // Cierra el extremo de lectura
        char mensaje[] = "Hola HIJO desde el PADRE!!";
        write(fd[1], mensaje, strlen(mensaje) + 1);
        close(fd[1]); // Cierra el extremo de escritura

        wait(NULL); // Espera a que el hijo termine antes de continuar
        printf("FIN.....\n");
    } 
    else if (pid == 0) {
        // ---- PROCESO HIJO ----
        close(fd[1]); // Cierra el extremo de escritura
        char buffer[100];
        read(fd[0], buffer, sizeof(buffer)); // Lee mensaje del pipe
        close(fd[0]); // Cierra el extremo de lectura

        printf("\t##==> Proceso HIJO: recibe mensaje del PADRE => %s\n", buffer);
        printf("FIN.....\n");
    } 
    else {
        perror("Error al crear el proceso");
        exit(1);
    }

    return 0;
}
