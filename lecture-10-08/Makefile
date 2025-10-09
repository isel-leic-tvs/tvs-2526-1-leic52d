all : tst_scall scallint_demo

	
scallint_demo: scallint_demo.c mywrite32.s 
	gcc -o scallint_demo  -g -Wall scallint_demo.c  mywrite32.s -static

tst_scall: tst_scall.c  mygetpid.s
	gcc -o tst_scall -g -Wall tst_scall.c  mygetpid.s chrono.c  
	
clean:
	rm -rf scallint_demo tst_scall *.o
