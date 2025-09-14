#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>


#define OUT_FILE "out.txt"

/**
 * this program just show the use of "dup2" system call
 * that copies the file descritor "fd" to file descriptor "1"
 * closing the last descriptor if it is not closed (avaiable)
 * 
 * the "dup" system call receive just on file descritor, and copies it
 * to the first avaiable descriptor on process descriptor table.
 * 
 * this enable, for instance, the redirect mechanism, illustrated here
 * 
 */
 
int main() {
	
 
	return 0;
	
}
