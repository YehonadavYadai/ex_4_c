MAIN_O=main.o
OTHER_O=mylib.o
C=gcc -g

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