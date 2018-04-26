# Makefile for myls 

CC = gcc 
CFLAGS = -Wall -c 
OBJS = myls.o 
TARGET = myls
DEPS = myls.c

mycp: $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

mycp.o: myls.c
	$(CC) $(CFLAGS) myls.c 

clean:
	rm -f $(OBJS)

