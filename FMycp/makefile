# Makefile for mycp 

CC = gcc 
CFLAGS = -Wall -c 
OBJS = mycp.o 
TARGET = "../mycp"
DEPS = mycp.c

mycp: $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

mycp.o: mycp.c
	$(CC) $(CFLAGS) mycp.c 

clean:
	rm -f $(OBJS)
