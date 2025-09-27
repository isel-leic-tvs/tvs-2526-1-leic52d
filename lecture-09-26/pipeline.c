#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>



/**
 * Below is a program that 
 * that executes a pipeline between two commands,
 * received as program arguments, in new processes,
 * waiting for the termination of the processes.
 * 
 */
 
int main(int argc, char *argv[]) {
	if (argc != 3) {
		fprintf(stderr, "usage: pipeline args...\n");
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
		close(p[0]);
	    dup2(p[1], STDOUT_FILENO);
		close(p[1]);
		if (execlp(argv[1], argv[1], NULL) == -1) {
			perror("error execing argv[1]");
		}
		exit(1);
	}
	
	if ((pid_cmd2 = fork()) == -1) {
		perror("error creating cmd1 process\n");
		exit(1);
	}
	else if (pid_cmd2 == 0) {
		// process for cmd2
		// redirect standard output and exec cmd2
		close(p[1]);
		dup2(p[0], STDIN_FILENO);
		close(p[0]);
		if (execlp(argv[2], argv[2], NULL) == -1) {
			perror("error execing argv[2]");
		}
		exit(1);
	}
	
	close(p[1]); // must be!
	close(p[0]);
	
 
	waitpid(pid_cmd2, NULL, 0);
	waitpid(pid_cmd1, NULL, 0);

	
	return 0;
}









