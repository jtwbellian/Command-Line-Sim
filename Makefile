CC=gcc
CFLAGS= -g -Wall
OBJS=mysh.o mycd.o mypwd.o myls.o mycat.o mycp.o
RUN_NAME=mysh

all: add

add: $(OBJS)
	$(CC) $(CFLAGS) -o $(RUN_NAME) $(OBJS) $(LIBS)

mysh.o: mysh.c
	$(CC) $(CFLAGS) -c mysh.c

mycd.o: mycd.c
	$(CC) $(CFLAGS) -c mycd.c

mypwd.o: mypwd.c
	$(CC) $(CFLAGS) -c mypwd.c

myls.o: myls.c
	$(CC) $(CFLAGS) -c myls.c

mycat.o: mycat.c
	$(CC) $(CFLAGS) -c mycat.c

mycp.o: mycp.c
	$(CC) $(CFLAGS) -c mycp.c

clean:
	rm -rf $(RUN_NAME)
	rm -rf $(OBJS)
