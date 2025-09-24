
all:  fork2 shell0 pipeline pipe0

 


fork2: fork2.c
	gcc -o fork2 -Wall fork2.c

pipeline: pipeline.c
	gcc -o pipeline -Wall pipeline.c

		
shell0: shell0.c utils.c
	gcc -o shell0 -Wall shell0.c utils.c

pipe0: pipe0.c  
	gcc -o pipe0 -Wall pipe0.c  
	
clean:
	rm -rf fork2 shell0 pipeline pipe0

