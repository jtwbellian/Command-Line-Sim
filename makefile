# Makefile for the shell

CC = gcc 
CFLAGS = -Wall -c 
OBJS = mysh.o 
TARGET = mysh
DEPS = builtin.c mysh.c

mysh: $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

mysh.o: mysh.c builtin.c
	$(CC) $(CFLAGS) mysh.c 

clean:
	rm -f $(OBJS)
