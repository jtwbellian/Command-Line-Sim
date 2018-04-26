# Makefile for mycat 

CC = gcc 
CFLAGS = -Wall -c 
OBJS = mycat.o 
TARGET = "../mycat"
DEPS = mycp.c

mycp: $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

mycp.o: mycat.c
	$(CC) $(CFLAGS) mycat.c 

clean:
	rm -f $(OBJS)

