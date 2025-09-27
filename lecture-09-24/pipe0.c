#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * this program uses a pipe to create a communication
 * channel between the child (the producer) and the parent (the consumer)
 * Incomplete...
 */
 
#define MAX_MSG_SIZE 256

int main() {
	int p[2];

	if (pipe(p) == -1) {
		perror("error creating pipe!");
		exit(1);
	}
 
	int pchild = fork();
	if (pchild == -1) {
		perror("error creating child process");
		exit(2);
	}
	else if (pchild == 0) { // child process code
		char msg[128];
	 
		close(p[0]);
		sprintf(msg, "hello from child %d", getpid());
		write(p[1], msg, strlen(msg)+1);
		close(p[1]);
		exit(0);
	}
	else { // parent code
		#define MAX_MSG 128
		char msg[MAX_MSG];
        
		// must close pipe output fd
		close(p[1]);
	
		int nr;
		int total = 0;

		// not necessary here, because a single atomic write is used on child to produce 
		// the output, but usually needed
		while((nr = read(p[0], msg + total, MAX_MSG-total)) > 0) {
			printf("%d bytes read\n", nr);
			total += nr;
		}

	 		
		waitpid(pchild, NULL, 0);
		close(p[0]);
		printf("father received: '%s'\n", msg);
	}
	return 0;
}
	
	
		
