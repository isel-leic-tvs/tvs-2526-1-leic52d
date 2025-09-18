#include <stdio.h>
#include <stdlib.h>

#include <fcntl.h>
#include <unistd.h>



#define FILENAME "xx.txt"

/**
 * This program opens the a file via fopen,
 * and get the file descriptor associated to FILE*,
 * using fileno library call
 * writing via fwrite and write.
 * Observe the result.
 */


int main() {
	// mix FILE fwrite and fd write
	// confusing!

    FILE *file = fopen("xpto.txt", "w+");
    if (file == NULL) {
      perror("error creating file via fopen");
      exit(1);
    }  
    // get the FILE associated fd
    int fd = fileno(file);
    
    if (fwrite("1234", 1, 4, file) != 4) {
      perror("error writing on file via fwrite");
      exit(1);
    }

    // comment next line and see the effect
    fflush(file);


    printf("file descriptor of file is %d\n", fd);

    if (write(fd, "56789", 5) != 5) {
      perror("error writing on file via write");
      exit(1);
    }

    //close(fd);
    fclose(file);

    return 0;
	 
}
