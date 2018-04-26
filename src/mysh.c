#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "extract.h"
#include "mycommand.h"
#include "myinput.h"

#define BUFSIZE 4096
#define PATH_MAX 1024

void handler(int);

int main() {
	if(signal(SIGQUIT, handler) == SIG_ERR) {
		printf("signal occurs error\n");
	}

	while(1) {
		pid_t pid;
		int status;
		int count;
		char buf[BUFSIZE];
		char *token;
		char *redirection;
		int bgOption = 0;
		char *fileName;
		int fd;

		char *currentDir; //get current directory
		char *cwd = getcwd(NULL, PATH_MAX);
		char *dirToken = strtok(cwd, "/");
		while(dirToken = strtok(NULL, "/")) {
			currentDir = dirToken;
		}


		printf("--------------------------\n");
		printf(".....Mysh has started.....\n");
		printf("Enter commands that you would like to run\n");
		printf("Hold ctrl+c to exit at any time...\n");
		printf("--------------------------\n");
		printf("[20122301 %s]$ ", currentDir);
		fgets(buf, BUFSIZE, stdin);

		if(feof(stdin)) { // when received EOF(ctrl+D)
			printf("Bye Bye~\n");
			return 0;
		}

		printf("getenv : %s\n", getenv("PATH"));

		if(strlen(buf) != 1) {
			buf[strlen(buf)-1] = '\0'; //remove \n
		} else { //when I received enter, ignore it.
			continue;
		}

		int final = strlen(buf)-1;
		if(buf[final] == '&') { //execute background working
			bgOption = WNOHANG;	
			buf[final]= '\0';
		}

		char *paramList[BUFSIZE];
		int index = 0;

		token = strtok(buf, " ");
		while(token != NULL) {
			paramList[index++] = token;
			token = strtok(NULL, " ");
		}

		if(strcmp(paramList[0], "exit") == 0) {
			printf("Bye Bye~\n");
			return 0;

		} else if(strcmp(paramList[0], "myenv") == 0) {
			myenv(index, paramList);

		} else if(strcmp(paramList[0], "cd") == 0) {
			cd(index, paramList);

		} else if(strcmp(paramList[0], "mypwd") == 0) {
			mypwd(index, paramList);

		} else if(strcmp(paramList[0], "myls") == 0) {
			myls(index, paramList);

		} else if(strcmp(paramList[0], "mycat") == 0) {
			mycat(index, paramList);

		} else if(strcmp(paramList[0], "mycp") == 0) {
			mycp(index, paramList);

		} else if(strcmp(paramList[0], "mymkdir") == 0) {
			mymkdir(index, paramList);

		} else if(strcmp(paramList[0], "myrmdir") == 0) {
			myrmdir(index, paramList);

		} else if(strcmp(paramList[0], "myrm") == 0) {
			myrm(index, paramList);

		} else {
			myinput(index, paramList);
			printf(": Invalid option\n");
		}

		pid = getpid();

		/*if(waitpid(pid, &status, bgOption) == -1) {
				printf("wait error\n");
				exit(1);
		} else {
			if(bgOption == WNOHANG) {
				printf("[1] %d\n" ,pid);
			}
		}*/
	}

	return 0;
}

void handler(int signo) {
	printf("Thanks for using our Shell\n");
	kill(getpid(), SIGTERM);
}
