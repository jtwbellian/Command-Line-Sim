#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define PATH_MAX 1024

char *getCurrentDir() {
	//char *currentPath = malloc(PATH_MAX);
	char *currentPath;
	char *currentDir;
	char *cwd;

	if(getcwd(currentPath, PATH_MAX) == NULL) {
		printf("getcwd() error\n");
	}

	/*char *token = strtok(currentPath, "/");
	while(token = strtok(NULL, "/")) {
		currentDir = token;
	}*/
	char *token = strtok(cwd, "/");
	while(token = strtok(NULL, "/")) {
		currentDir = token;
	}

	//free(currentPath);

	return currentDir;
}


char *extraction(char *command) {
	int leng;
	int existing;
	char *filePath;
	char *pathes;

	existing = -1;
	pathes = (char *)malloc(strlen(getenv("PATH"))*sizeof(char));
	strcpy(pathes, getenv("PATH"));

	char *path = strtok(pathes, ":");
	while(path = strtok(NULL, ":")) {
		leng = strlen(command) + strlen(path)+1;
		filePath = (char *)malloc(leng * sizeof(char));

		strncpy(filePath, path, strlen(path)*sizeof(char));
		strcat(filePath, "/");
		strcat(filePath, command);

		existing = access(filePath, R_OK);
		if(existing == 0) {
			break;
		}
	
	}

	if(existing == 0) {
		return filePath;

	} else {
		return NULL;
	}
}
