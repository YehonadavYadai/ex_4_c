MAIN_O=main.o
OTHER_O=mylib.o
C=gcc -g

h:
	gcc test.c 
	./a.out
all:frequency v
allb:frequency c
c:
	./frequency r<input.txt
v:
	valgrind --track-origins=yes ./frequency r<input.txt
	
frequency:main.c
	$(C) main.c -o frequency
.PHONY:clean all
    
clean:
	rm *.o  