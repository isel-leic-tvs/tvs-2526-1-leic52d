#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main() {
   // mix fd and FILE output

   FILE *file = fopen("xpto.txt", "w+");
   if (file == NULL) {
      perror("error creating file");
      exit(1);
   }
  
   if ( fwrite("1234", 1, 4, file) != 4) {
      perror("error writing on file");
      exit(1);
   }
   
   // use file output via fd
   int fd = open("xpto.txt", O_WRONLY | O_CREAT, 0644);
   if (fd ==  -1) {
       perror("error creating file via fd");
      exit(1);
   }
   
   if (write(fd, "56789", 5) != 5) {
      perror("error writing on file");
      exit(1);
   }

   fclose(file);
   close(fd);

   return 0;
}
