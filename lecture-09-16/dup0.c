#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


#define OUT_FILE "out.txt"

/**
 * this program just show the use of "dup" and "dup2" system call
 * that copies the file descritor "fd" to file descriptor "1" (STDOUT_FILENO)
 * closing the last descriptor if it is not closed (avaiable)
 * 
 * the "dup" system call receive just on file descritor, and copies it
 * to the first avaiable descriptor on process descriptor table.
 * 
 * this enable, for instance, the redirect mechanism, illustrated here
 * 
 */
 
int main() {
	int fdout = open("out.txt", O_WRONLY | O_CREAT, 0664);
	close(STDOUT_FILENO);
	dup(fdout);
	close(fdout);
	write(STDOUT_FILENO /* 1*/, "Hello\n", 6);
 
	return 0;
	
}
