#include <stdio.h>
#include <stdlib.h>

void mypwd(int size, char **argv) {
	if(size == 1) {
		char *currentPath = malloc(1024);

		if(getcwd(currentPath, 1024) == '\0') {
			perror("getcwd");
		}

		printf("%s\n", currentPath);
	} else {
		if(strcmp(argv[1], "--help") == 0) {
			printf("mypwd print current working directory\nmypwd : usage : mypwd\n");
			printf("[option] --help : print mypwd command usage\n");

			return;

		} else {
			int i;
			for(i = 0; i < size; i++) {
				printf("%s ", argv[i]);
			}
			printf(": Invalid option\n");
		}
	}
}
