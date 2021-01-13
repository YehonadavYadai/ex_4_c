MAIN_O=main.o
OTHER_O=mylib.o
C=gcc -g


all:frequency 

	
frequency:main.c
	$(C) main.c -o frequency
.PHONY:clean all
    
clean:
	rm *.o  