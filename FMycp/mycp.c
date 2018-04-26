#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

void mycp(int size, char **argv) {
	int ofd, nfd;
	int old, new;
	char buf[10000];
	char *reverse;
	char *source;
	char *dest;

	if(size == 2) {
		if(strcmp(argv[1], "--help") == 0) {
			printf("mycp command copies a file to a destination file\n");
			printf("usage : mycp [-reverse] [FILENAME] [FILENAME]\n");
			printf("[option] --help : print mycp command usage.\n\t-reverse : copy file reverse\n");

			return;
		} else {
			int i;
			for(i = 0; i < size; i++) {
				printf("%s ", argv[i]);
			}

			printf(": Invalid option\n");

			return;
		}
	} else if(size == 3) {
		source = argv[1];
		dest = argv[2];

	} else if(size == 4) {
		source = argv[2];
		dest = argv[3];

	} else {
		int i;
		for(i = 0; i < size; i++) {
			printf("%s ", argv[i]);
		}

		printf(": Invalid option\n");

		return;
	} 

	ofd = open(source, O_RDONLY);
	if(ofd == -1) {
		int i;
		for(i = 0; i < size; i++) {
			printf("%s ", argv[i]);
		}

		printf(": cannot open file\n");
		return;
	}
	old = read(ofd, buf, sizeof(buf));
	if(old == -1) {
		int i;
		for(i = 0; i < size; i++) {
			printf("%s ", argv[i]);
		}

		printf(": cannot read file\n");
		return;
	}
	buf[old] = '\0';

	if(size == 4) {
		if(strcmp(argv[1], "-reverse") == 0) {
			int i = 0;
			int j;
			reverse = (char *)malloc(strlen(buf));
				for(j = strlen(buf)-1; j > 0; j--) {
					reverse[i++] = buf[j];
				}
			printf("%s\n", reverse);
			strcpy(buf, reverse);
		} else {
			int i;
			for(i = 0; i < size; i++) {
				printf("%s ", argv[i]);
			}

			printf(": Invalid option\n");
			return;
		}
	}

	int acc;
	if(acc = (access(dest, F_OK)) == -1) {
		nfd = open(dest, O_CREAT | O_WRONLY, 0644);
	} else if(acc == 0) {
		nfd = open(dest, O_WRONLY | O_TRUNC);
	}
	if(nfd == -1) {
		int i;
		for(i = 0; i < size; i++) {
			printf("%s ", argv[i]);
		}

		printf(": cannot open file\n");
		return;
	}

	if(write(nfd, buf, strlen(buf)) != strlen(buf)) {
		int i;
		for(i = 0; i < size; i++) {
			printf("%s ", argv[i]);
		}

		printf(": cannot read file\n");
		return;
	}
	
	printf("Successfully copied!\n");
	close(ofd);
	close(nfd);
}


int main( int argc, char ** argv)
{
	mycp(argc, argv);
}
