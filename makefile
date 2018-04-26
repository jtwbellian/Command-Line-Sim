# Makefile for the shell

CC = gcc 
CFLAGS = -Wall -c 
OBJS = mysh.o 
TARGET = mysh
DEPS = builtin.c mysh.c


mysh: $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

mysh.o: $(DEPS)
	#(CC) $(CFLAGS) -o mysh.o 


clean:
	rm -f $(OBJS)
