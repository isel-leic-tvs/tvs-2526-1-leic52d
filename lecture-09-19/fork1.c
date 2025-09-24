#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define DELAYED_WAIT
//#define WITH_WAIT
#define DELAYED_CHILD

int main() {
	
	
	printf("parent pid: %d\n", getpid());
	
	// create new process and wait for his termination

	pid_t child = fork();

	if (child == -1) {
		perror("error on fork");
		exit(1);
	}
	else if (child == 0) {
		printf("i'm the child with pid %d\n", getpid());
#ifdef DELAYED_CHILD
		sleep(5);
#endif
        printf("child termination!\n");
		exit(5);
	}
	else {
		printf("child %d created\n", child);
	}

	int status;
	waitpid(0, &status, 0);
	if (WIFEXITED(status)) {
		printf("child terminated with status code = %d\n", WEXITSTATUS(status));
	}
	else {
		printf("abnormal termination!\n");
	}
#ifdef DELAYED_WAIT
	sleep(20);
#endif
	printf("parent termination!\n");
	return 0;
}
