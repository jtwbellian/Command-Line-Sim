#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "builtin.c"
#define WORD_LEN 20
#define CHAR_LEN 50
#define NUM_FUNC 5

char* customFunc[] = {"mycd", "pwd", "mycp", "mycat", "myls"};


//fgets stored into line char array
//any newlines are replaced with the null bit
void getLine(char str[]){
	fgets(str, CHAR_LEN, stdin);
	int i = 0;
	while(str[i] != '\n'){ i++; }
	str[i] = '\0';
}

//Parse the line for each word
int parseLine(char* wordArr[], char str[]){
	int i = 0;
	char* token = " ";
	wordArr[i] = strtok(str, token);
	if (wordArr[i] == NULL) { return -1; }
	while(wordArr[i] != NULL){
		wordArr[++i] = strtok(NULL, token);
	}
	return 1;
}

//Get and parse the line
int getAndParse(char* wordArr[], char str[]){
	printf("Group 1 mysh $:");
	int n;
	getLine(str);
	n = parseLine(wordArr, str);
	if (n == -1){ 
		printf("No command entered...\n");
	}
	return 1;
}


int findFunc(char* wordArr[]){
	int i;
	for (i = 0; i < NUM_FUNC; i++){
		if (strcmp(wordArr[0], customFunc[i]) == 0){
			if (strcmp(wordArr[0], "mycd") == 0){ 
				mycd(wordArr);
				return 1; 
			}
			else if(strcmp(wordArr[0], "pwd") == 0){ 
				pwd();
				return 1;
			}
			else if(strcmp(wordArr[0], "mycp") == 0){
				char dest[50];
				strcpy(dest, "./");
				strcat(dest, wordArr[0]);
				execvp(dest, wordArr);
			}
			else if(strcmp(wordArr[0], "mycat") == 0){
				char dest[50];
				strcpy(dest, "./");
				strcat(dest, wordArr[0]);
				execvp(dest, wordArr);
			}
			else{
				char dest[50];
				strcpy(dest, "./");
				strcat(dest, wordArr[0]);
				execvp(dest, wordArr);
			}	
		}
	}
	
	if(execvp(wordArr[0], wordArr) < 0){
		printf("Command doesn't exist! Enter another command.\n");
	}
}

int main(int argc, char* argv[]){
	pid_t pid;
	char* wordArr[WORD_LEN];
	char str[CHAR_LEN];
	printf("--------------------------\n");
	printf(".....Mysh has started.....\n");
	printf("Enter commands that you would like to run\n");
	printf("Hold ctrl+c to exit at any time...\n");
	printf("--------------------------\n");
	while(getAndParse(wordArr, str)){
		if ((pid = fork()) == 0){
			findFunc(wordArr);		
		}
		else{
			wait(NULL);
		}
	}
}
