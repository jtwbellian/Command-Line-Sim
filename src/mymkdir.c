#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

void mymkdir(int size, char **argv) {
	int err;
	char *token;
	char *dirname;
	char *dir[1024];
	int index = 0;

	if(size == 2) {
		if(strcmp(argv[1], "--help") == 0) {
			printf("mymkdir command make directories\n");
			printf("usage : mymkdir [-p] [DIRECTORY]\n");
			printf("[option] --help : print mymkdir command usage\n\t-p : create directory as required\n");

			return;
		} else {
			dirname = argv[1];
			char *find = strchr(dirname, '/');
			if(find != NULL) {
				int i;
				for(i = 0; i < size; i++) {
					printf("%s ", argv[i]);
				}

				printf(": You need -p option\n");

				return;
			}

			err = mkdir(dirname, 0755);
			if(err == -1) {
				int i;
				for(i = 0; i < size; i++) {
					printf("%s ", argv[i]);
				}

				printf(": cannot make directory\n");

				return;
			}
		}
	} else if(size == 3) {
		if(strcmp(argv[1], "-p") == 0) {
			token = strtok(argv[2], "/");
			while(token != NULL) {
				dir[index++] = token;
				token = strtok(NULL, "/");
			}
			int i;
			for(i = 0; i < index; i++) {
				if(access(dir[i], F_OK) == 0) {
					chdir(dir[i]);
					continue;
				}
				if(err = mkdir(dir[i], 0755)) {
					int err_index;
					for(err_index = 0; err_index < size; err_index++) {
						printf("%s ", argv[err_index]);
					}
					printf(": cannot make directory\n");

					return;
				}
				chdir(dir[i]);
			}
			int j;
			for(j = 0; j < index; j++) {
				chdir("../");
			}
		} else {
			int i;
			for(i = 0; i < size; i++) {
				printf("%s ", argv[i]);
			}
			printf(" : Invalid option\n");
			return;
		}
	}
}
