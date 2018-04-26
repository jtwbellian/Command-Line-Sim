#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

void myrmdir(int size, char **argv) {
	int err;

	if(size == 2) {
		if(strcmp(argv[1], "--help") == 0) {
			printf("myrmdir command remove directory\n");
			printf("usage : myrmdir [FILENAME]\n");
			printf("[option] --help : print myrmdir command usage\n");

			return;

		} else {
			err = rmdir(argv[1]);	
			if(err == -1) {
				int i;
				for(i = 0; i < size; i++) {
					printf("%s ", argv[i]);
				}
				printf(": %s\n", strerror(errno));
			}
		}
	} else {
		int i;
		for(i = 0; i < size; i++) {
			printf("%s ", argv[i]);
		}
		printf(": This command needs two parameters\n");
		return;
	}
}
