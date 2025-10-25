// client for libmath.so with dynamic linking in load time

#include <stdio.h>
#include <unistd.h>
 

// the used function in libmath.so
long add(int i1, int i2);
int get_count_calls();

void  susp_point(char *msg) {
	printf("%s: press return to  continue...", msg);
	getchar();
}


int main() {
	printf("my pid is %d\n", getpid());
	susp_point("start");
	
	long v = add(2, 3);
	
	printf("add(2, 3)=%ld\n", v);
	printf("count_calls()=%d\n", get_count_calls());
	susp_point("end");
	return 0;
}
