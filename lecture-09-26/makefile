
all:  pipeline  segvtest


pipeline: pipeline.c
	gcc -o pipeline -g -Wall pipeline.c

segvtest: segvtest.c  
	gcc -o segvtest -g -Wall segvtest.c  
	
clean:
	rm -rf pipeline  segvtest
 
