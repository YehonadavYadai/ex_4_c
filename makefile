MAIN_O=main.o
OTHER_O=mylib.o
C=gcc -g


run:do frequency 
	./frequency<input.txt
do:main.c
	$(C) main.c -o frequency
.PHONY:clean all
    
clean:
	rm *.o  