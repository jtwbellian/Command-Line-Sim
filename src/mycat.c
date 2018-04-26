#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void mycat(int size, char **argv) {
	char buf[256];
	char *filename = argv[1];	
	int fd, n, len;
	int status = 0;

	if(size == 2) {
		if(strcmp(argv[1], "--help") == 0) {
			printf("mycat command print files\n");
			printf("usage : mycat [FILENAME] [NUMBER]\n");
			printf("[option] --help : print mycat command usage\n");

			return;

		} else {
			len = sizeof(buf);
		}
	} else if(size == 3) {
		len = atoi(argv[2]);
		if(len < 0) {
			int i;
			for(i = 0; i < size; i++) {
				printf("%s ", argv[i]);
			}
			printf(": number must bigger than 0\n");
			return;
		}
	} else {
		int i;
		for(i = 0; i < size; i++) {
			printf("%s ", argv[i]);
		}
		printf(": You need two or three parameters\n");

		return;
	}

	fd = open(filename, O_RDONLY);
	if(fd == -1) {
		int i;
		for(i = 0; i < size; i++) {
			printf("%s ", argv[i]);
		}
		printf(": cannot open file\n");
		
		return;
	}
	n = read(fd, buf, len);
	if(size == 3) {
		if(len < strlen(buf)) {
			status = 1;	
		}
	}

	if(n == -1) {
		int i;
		for(i = 0; i < size; i++) {
			printf("%s ", argv[i]);
		}
		printf(": cannot read file\n");

		return;
	}
	
	buf[n] = '\0';

	close(fd);

	printf("%s", buf);
	if(status == 1) {
		printf("\n");
	}
}
