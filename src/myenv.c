#include <stdio.h>
#include <stdlib.h>

extern char **environ;

void myenv(int size, char **argv) {
	if(size == 1) { // received command only
		int i = 0;

		while(environ[i]) {
			printf("%s\n", environ[i++]);
		}

	} else { // received command and options
		if(strcmp(argv[1], "--help") == 0) {
			printf("myenv command print enviornment variable\n");
			printf("usage : myenv [name=value]\n");
			printf("[option] --help : print myenv command usage\n");
		} else {
			char *res;
			res = getenv(argv[1]);
			
			if(res == NULL) {
				printf("\n");
				return;
			}
			printf("%s\n", res);
		}
	}
}
