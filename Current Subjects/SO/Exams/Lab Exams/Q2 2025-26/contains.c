#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void Usage(){
    printf("Usage: ./contains file word (only 1 word is allowed)\n");
    exit(EXIT_SUCCESS);
}
// jamon
int main(int argc, char* argv[]){
    if (argc != 3) Usage();
    int st;
    switch(fork()){
        case -1:
            printf("Fork Error\n");
            exit(EXIT_FAILURE);
        case 0:
            execlp("grep", "grep","-q", argv[2], argv[1], (char*) 0);
            exit(EXIT_FAILURE);
        default:
            waitpid(-1, &st, 0);
            if (!WEXITSTATUS(st)){
                printf("La palabra %s está en el fichero\n", argv[2]);
                exit(EXIT_SUCCESS);
            } else{
                printf("La palabra %s no está en el fichero\n", argv[2]);
                exit(EXIT_FAILURE);
            }
    }
}
