all : sigtest nolib scall_demo 
FLAGS= -g -Wall 

sigtest: sigtest.c
	gcc -o sigtest $(FLAGS) sigtest.c

nolib:
	as -c -o nolib.o nolib.s
	ld -o nolib nolib.o 

scall_demo: scall_demo.c mywrite.s 
	as -c -o mywrite.o mywrite.s
	gcc -o scall_demo $(FLAGS) scall_demo.c mywrite.o
	 
clean:
	rm -rf sigtest nolib scall_demo  *.o
