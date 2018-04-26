#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "myinput.h"

void myrm(int size, char **argv) {
	if(size == 2) {
		if(strcmp(argv[1], "--help") == 0) {
			printf("myrm command delete file\n");
			printf("usage : myrm [-rf] [FILENAME]\n");
			printf("[option] -- help : print myrm command usage\n\t-rf : delete file or directory forcely\n");

			return;
		} else {
			int err;

			err = unlink(argv[1]);
			if(err == -1) {
				myinput(size, argv);
				printf(": %s\n", strerror(errno));

				return;
			}
		}
	} else if(size == 3) {
		if(strcmp(argv[1], "-rf") == 0) {

		} else {
			myinput(size, argv);
			printf(": Invalid option\n");

			return;
		}
	}
}
