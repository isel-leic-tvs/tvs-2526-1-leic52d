#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "utils.h"

 


/**
 * Below is a program that 
 * that executes a command (with parameters)
 * received on their arguments, in a new process,
 * waiting for the termination of that process.
 * 
 * Note the use of "fork" and "execvp" Linux API operations
 */
 
int main(int argc, char *argv[]) {
	if (argc < 2) {
		fprintf(stderr, "usage: shell0 args...\n");
		exit(1);
	}
	
	int child_pid;
	
	if ((child_pid = fork()) == -1) {
		perror("can't create new process");
		exit(1);
	}
	else if (child_pid == 0) {
	   // exec command
	}
	else {
		waitpid(child_pid, NULL, 0);
	}
	
	return 0;
}









