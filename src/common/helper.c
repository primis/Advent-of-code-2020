// Advent of code 2020 helper functions
// Can be included using "common/helper.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fileSize(FILE* fp)
{
    int size, previous;
    previous = ftell(fp);
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fseek(fp, previous, SEEK_SET);
    return size;
}

// Reads a file into a buffer for use, returns size of the file
char* readFile(const char* name)
{
    int size, i;
    FILE *fp;
    char *buf;
    if(name == NULL)
    {
        fprintf(stderr, "No filename found\n");
        return NULL;
    }

    fp = fopen(name, "r");
    if(fp == NULL)
    {
        fprintf(stderr, "Could not open file \"%s\"\n", name);
        return NULL;
    }

    size = fileSize(fp);

    buf = malloc(size+2);
    memset(buf, 0, size+2);
    if(buf == NULL)
    {
        fprintf(stderr, "Malloc failed to allocate %d bytes\n", size);
        return NULL;
    }

    while(!feof(fp))
    {
        *(buf++) = fgetc(fp);
    }

    fclose(fp);
    return (buf - size);
}

// Reads a buffer, returns the number of lines
int numLines(char *buf)
{
    int n = 0;
    while(*buf != 0)
    {
        if(*buf == '\n')
        {
            n++;
        }
        buf++;
    }
    return n;
}

// Reads a list of numbers (one per line) into an array from a string
int *arrayNumbersFromFile(char* name, int *numElements)
{
    int i, trash, n=0;
    int *arr;
    FILE *fp;

    if(name == NULL)
    {
        fprintf(stderr, "No Filename found\n");
        return NULL;
    }

    fp = fopen(name, "r");
    if(fp == NULL)
    {
        fprintf(stderr, "Error opening File\n");
        return NULL;
    }

    while(fscanf(fp, "%d", &trash) != EOF)
    {
            n++;
    }
    rewind(fp);

    arr = malloc(sizeof(int)*n);
    if(arr == NULL)
    {
        *numElements = -1;
        return NULL;
    }

    for(i = 0; i < n; i++)
    {
       fscanf(fp, "%d", &arr[i]);
    }

    fclose(fp);
    *numElements = n;
    return arr;
}
