CC = gcc
CFLAGS = -Wall

COM_OBJ = complex.o
STACK_OBJ = stack.o stack_test.o
ALL_OBJ = $(COM_OBJ) $(STACK_OBJ)

.PHONY: clean cleanall all bundles
all: stack_test clean


stack_test: $(COM_OBJ) $(STACK_OBJ) stack.h
	$(CC) -o stack_test $(COM_OBJ) $(STACK_OBJ)

$(ALL_OBJ): %.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@


cleanall: clean
	-rm -f stack_test

clean:
	-rm -f *.o

