#include <stdio.h>
#include <stdlib.h>
#include "myinput.h"

void myps(int size, char **argv) {
	if(size == 1) {
		printf(" UID PID PPID GID SID TIME TTY CMD\n");

		return;

	} else if(size == 2) {
		

	} else {
		myinput(size, argv);
		printf(": Invalid option\n");

		return;
	}
}
