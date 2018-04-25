#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>

void mycat ( char *fileName ) {

    char inputfile[500];

    char *pos;
    if ((pos=strchr(fileName, '\n')) != NULL)
        *pos = '\0';

    char *inputflag = strchr (fileName, '<');
    char *outputflag = strchr (fileName, '>');
    char *spaceflag = strchr (fileName, ' ');
    if ( inputflag != NULL )
    {
        printf("Input Flag found");
        printf("%c",*(inputflag+1));
    }

    if (access ( fileName, F_OK ) != -1)
    {
        printf("Do stuff\n");
    }
    else
    {
        printf("Fail");
    }
}

int main ()
{
    char fileName[500];
    printf("Input File to CAT: ");
    fgets(fileName, sizeof(fileName), stdin);

    mycat (fileName);


    return 0;
}
