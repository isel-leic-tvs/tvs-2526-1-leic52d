
all:  pipeline sigtest segvtest

 

 

pipeline: pipeline.c
	gcc -o pipeline -g -Wall pipeline.c

		
sigtest: sigtest.c  
	gcc -o sigtest -g -Wall sigtest.c 

segvtest: segvtest.c  
	gcc -o segvtest -g -Wall segvtest.c  
	
clean:
	rm -rf pipeline sigtest segvtest
 
