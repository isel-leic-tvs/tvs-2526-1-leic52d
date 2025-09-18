#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/**
 * This program opens the same file twice,
 * first open done via fopen and second via open,
 * writing from the two obtained descriptors.
 * Observe the result.
 */

 

int main() {

   FILE *file = fopen("xpto.txt", "w+");
   if (file == NULL) {
      perror("error creating file");
      exit(1);
   }
  
   if (fwrite("1234", 1, 4, file) != 4) {
      perror("error writing on file via fwrite");
      exit(1);
   }

      
   // access file via open
   int fd = open("xpto.txt", O_WRONLY);
   if (fd == -1) {
      perror("error opening file via open");
      exit(1);
   }

   
   if (write(fd, "56789", 5) != 5) {
      perror("error writing on file via write");
      exit(1);
   }
   fclose(file);
  
   close(fd);

   return 0;
}
