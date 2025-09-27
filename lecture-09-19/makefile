
all: fork1 fork0  exec0 


fork0: fork0.c
	gcc -o fork0 -Wall fork0.c

fork1: fork1.c
	gcc -o fork1 -Wall fork1.c




exec0: exec0.c
	gcc -o exec0 -Wall exec0.c

		
shell0: shell0.c utils.c
	gcc -o shell0 -Wall shell0.c utils.c
	
clean:
	rm -rf fork1 fork2 fork0 exec0 shell0

