MAIN_O=main.o
OTHER_O=mylib.o
C=gcc -g



do:maintest.c
	$(C) maintest.c
run:do a.out
	./a.out<input.txt



	
all:final
final:$(MAIN_O) mylib.so    
	$(C) $(MAIN_O) ./mylib.so -o $@
mylib.so:$(OTHER_O)
	$(C) -shared $^ -o $@
MAIN_O:main.c mylib.h 
	$(C) -c main.c
OTHER_O: mylib.c mylib.h
	$(C) -c mylib.c

.PHONY:clean all
    
clean:
	rm *.o *.so final