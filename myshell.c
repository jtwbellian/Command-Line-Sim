#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define WORD_LEN 20
#define CHAR_LEN 50

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
//	printf("Print parseline\n");
//	int j;
//	for (j = 0; j <= i; j++){ printf("word : %s\n", word[j]); }
	
}

//Get and parse the line
//Returns -1 if no command entered
int getAndParse(char* wordArr[], char str[]){
	int n;
	getLine(str);
	n = parseLine(wordArr, str);
	if (n == -1){ 
		printf("No command entered...\n");
		return -1;
	}
	return 1;
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
			execvp(wordArr[0],wordArr);	
		}
		else{
			wait(NULL);
		}
	}
}
