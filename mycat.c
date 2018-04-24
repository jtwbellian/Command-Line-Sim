#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>

void mycat ( char *fileName ) {

    char outputFile[500];
    char fileToOpen[500];
    int outputFlag = 1;
    int inputFlag = 1;
    int exitFlag = 1;
 
    int i = 0;
    int count = 0;

    char *pos;
    if ((pos=strchr(fileName, '\n')) != NULL)
        *pos = '\0';

    while ( (fileName[i] != '\0') && (exitFlag == 1) && (fileName[i] != '\n') 
            && (fileName[i] != EOF) )
    { 
        if ( fileName[i] == '>' )
        {
            outputFlag = 0;
            printf("Output detected\n");
            int outCount = 0;
            for ( int n = i+1; (fileName[n] != '\0') 
                    && (fileName[n] != ' '); ++n )
            {
                outputFile[outCount] = fileName[n];
                ++outCount;
                printf("%c", fileName[n]);
            }
            exitFlag = 0;
        printf("%s\n\n\n", outputFile);
        }
        else if ( fileName[i] == '<' )
        {
            inputFlag = 0;
            printf("Input Detected\n");
            int inCount = 0;
            for ( int j = i+1; (fileName[j] != '\0') && (fileName[j] != '>') 
                && (fileName[j] != ' '); ++j )
            {
                fileToOpen[inCount] = fileName[j];
                ++inCount;
            }
        }
        else
        {
            if ( (fileName[i] != ' ') && (inputFlag==1) && (fileName[i] != '\0') )
            {
            fileToOpen[count] = fileName[i];
            ++count; 
            }
        }
    ++i;
    }
printf("%s", fileToOpen);
    if ( (access ( fileToOpen, F_OK ) != -1) && (outputFlag == 1) )
    {
        FILE *fptr = fopen(fileToOpen, "r");
        if (fptr == NULL)
        {
           printf("Cannot open file \n");
           exit(0);
        }

        char ch = fgetc(fptr);
        while (ch != EOF)
        {
            printf ("%c", ch);
            ch = fgetc(fptr);
        }
        fclose(fptr);
    }
    else if ((access ( fileToOpen, F_OK ) != -1) && (outputFlag == 0))
    {
        printf("writing to file: %s", outputFile);

        FILE *fptr = fopen(fileToOpen, "r");
        if (fptr == NULL)
        {
           printf("Cannot open file \n");
           exit(0);
        }

        FILE* file_ptr = fopen(outputFile, "w");
        
        char ch = fgetc(fptr);
        while (ch != EOF)
        {
            fprintf (file_ptr,"%c", ch);
            ch = fgetc(fptr);
        }
        fclose(file_ptr);
    }
    else 
    {
        printf("ERROR mycat: %s: No such file or directory\n", fileName);
    }
}

int main () {
    char fileName[500];
    printf("Input File to CAT: ");
    fgets(fileName, sizeof(fileName), stdin);

    mycat(fileName);
    return 0;
}
