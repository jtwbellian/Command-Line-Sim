// mycd - changes the current directory
// pwd - prints the working directory 
// Programmed by James Bellian

#include<stdio.h>
#include<string.h>

#define MAXSIZE 500

int mycd(char * comm[])
{
	if (comm[1] == NULL)
	{
		printf("Expected argument - none given!\n");
		return 0;
	} 

	char dir[MAXSIZE];
	strcpy(dir, comm[1]);
	
	if (chdir(comm[1]) < 0) 
	{
		printf("Unknown directory \"%s\"\n", dir);
		return 0;
	}
	
	return 1;

}

void pwd()
{
	char wd[MAXSIZE];
	getcwd(wd,MAXSIZE);	
	printf("%s\n", wd);	
}

