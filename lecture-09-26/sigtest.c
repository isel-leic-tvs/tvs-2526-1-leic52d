/**
 * illustrates inheritance of signal handling in fork
 */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

void sigint_handler(int s) {
    printf("SIGINT caught at process %d\n", getpid());
}
 

int main(int argc, char *argv[]) {
    signal(SIGINT, sigint_handler);
    
    printf("on parent process is %d\n", getpid());
   
    if (fork() == 0) {
         printf("on child  process %d, press enter to terminate... ", getpid());
         getchar();
         printf("child  process %d, terminating\n", getpid());
         exit(0);
    }
    else {
        wait(NULL);
        printf("child terminated!\n");
    }
    return 0;
}
