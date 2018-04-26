#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "myinput.h"

void cd(int size, char **argv) {
	//TODO: move before path
	if(size == 1) {
		char *homePath = getenv("HOME"); //get home path	
		chdir(homePath);

	} else if(size == 2) {
		int fd, n;
		char *buf, *token;

		int index = 0;
		if(strcmp(argv[1], "~") == 0) {
			char *homePath = getenv("HOME"); //get home path	
			chdir(homePath);
		} else if(strcmp(argv[1], "--help") == 0) {
			printf("cd command change directory\n");
			printf("usage : cd [FILENAME]\n");
			printf("[option] --help : print cd usage\n\t-b : move before path\n");

			return;
		}

		chdir(argv[1]);

	} else if(size == 3) {
		if(strcmp(argv[1], "-b")== 0) {
			int i, num;
			num = atoi(argv[2]);

			if(num < 0) {
				myinput(size, argv);
				printf(": Invalid Value\n");
				return;
			}

		} else {
			myinput(size, argv);
			printf(": Invalid Option\n");
			return;
		}
	}
}
