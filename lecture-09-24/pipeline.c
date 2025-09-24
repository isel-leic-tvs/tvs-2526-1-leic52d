#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "utils.h"



/**
 * Below is a program that 
 * that executes a pipeline between two commands,
 * received as program arguments, in new processes,
 * waiting for the termination of the processes.
 * 
 */
 
int main(int argc, char *argv[]) {
	if (argc < 2) {
		fprintf(stderr, "usage: shell0 args...\n");
		exit(1);
	}
	
	int p[2];
	
	if (pipe(p) == -1) {
		perror("error creating pipe\n");
		exit(1);
	}
	// launch a process and wait for his termination
	
	int pid_cmd1, pid_cmd2;

	if ((pid_cmd1 = fork()) == -1) {
		perror("error creating cmd1 process\n");
		exit(1);
	}
	else if (pid_cmd1 == 0) {
		// process for cmd1
		// redirect standard output and exec cmd1
	    
	}
	
	if ((pid_cmd2 = fork()) == -1) {
		perror("error creating cmd1 process\n");
		exit(1);
	}
	else if (pid_cmd2 == 0) {
		// process for cmd1
		// redirect standard output and exec cmd2
	}
	
	// ????
	
 	waitpid(pid_cmd1, NULL, 0);
	waitpid(pid_cmd2, NULL, 0);

	
	return 0;
}









