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
    exit(0);
}
 

int main(int argc, char *argv[]) {
    //signal(SIGINT, SIG_IGN);
    
    printf("on parent process is %d\n", getpid());
   
    if (fork() == 0) {
         signal(SIGINT, sigint_handler);
         printf("on child  process %d\n", getpid());
         printf("Waiting for input...");
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
