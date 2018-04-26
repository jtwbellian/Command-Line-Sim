#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>

void mycat ( char *fileToOpen, char *outputFile, int argc ) {
  
    int outputFlag = 1;
    if ( argc == 3 )
    {
        outputFlag = 0;
        char *outputthing = strstr(outputFile, ">");
        if (outputthing) {
            outputFile++;
        }
    }
    
    char *inputthing = strstr(fileToOpen, "<");
    if (inputthing) {
        fileToOpen++;
    }

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
        printf("ERROR mycat: %s: No such file or directory\n", fileToOpen);
    }
}

int main (int argc, char** argv) {

    if (argc <= 1)
    {
        printf("No file specified");
        exit(1);
    }
  
    mycat(argv[1], argv[2], argc);
    return 0;
}
