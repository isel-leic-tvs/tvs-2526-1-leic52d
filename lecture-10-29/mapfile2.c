/**-------------------------------------
 * Criação programática de uma região de memória 
 * para maper em memória o ficheiro "numbers.dat".
 * Observar as consequências no Resident Set do processo
 * Execute duas instâncias (filemap2 e filemap2 half) e observe os respectivos "smaps"
 * analisando a evolução dos correspondentes Pss
 *
 * Jorge Martins, outubro de 2025
 */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include "filespecs.h"

void  suspend(char *msg) {
	printf("%s: press return to  continue...", msg);
	getchar();
}

int main(int argc, char *argv[]) {
	printf("my pid is %d\n", getpid());
	int fd = open(INTS_FILENAME, O_RDONLY);
	size_t read_size = (argc == 1) ? NUMBERS_COUNT :  NUMBERS_COUNT /2;
    
	suspend("start!");
	if (fd < 0) {
		perror("error creating numbers file");
		return 1;
	}
	
	// find file size
	off_t size = lseek(fd, 0, SEEK_END);
    
	printf("FILE SIZE =%ld\n", size);
	
	
	// DO MAP 
	// testar com MAP_SHARED e MAP_PRIVATE
	void *mapbase = mmap(NULL, size/2, PROT_READ , MAP_SHARED, fd, 0);
	
	if (mapbase == MAP_FAILED) {
		perror("error mapping numbers file");
		return 3;
	}
	
	printf("memory mapped at %p\n", mapbase);
	suspend("after file map");
	
	close(fd);
	
	int *ints = (int *) mapbase;
	
    // note here 
	for(int i=0; i < read_size; ++i) {
		printf("%d\n",ints[i]);
	}
	
	suspend("after file show");
	 
	
	if (munmap(mapbase, size) == -1) {
		perror("error unmapping numbers file");
		return 4;
	}
	
	return 0;
}
