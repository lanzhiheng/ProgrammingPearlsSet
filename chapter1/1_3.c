#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "./share.h"

unsigned long * readFromFile (const char * filename, const unsigned long length);

// read array from the file by file name and the array length
unsigned long * readFromFile (const char * filename, const unsigned long length) {
    unsigned long temp, i = 0;
    unsigned long * array = malloc(length * sizeof(unsigned long));
    FILE * fptr;
    fptr = fopen(filename, "r");

    if(fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }


    while (fscanf(fptr, "%lu", &temp) != EOF) {
        array[i++] = temp;
    }
    return array;
}

int main() {
    unsigned long * array = readFromFile("./tmp/output", ARRAY_SIZE);
    /* for (int i = 0; i < 1000; i ++) { */
    /*     printf("%lu\n", array[i]); */
    /* } */
    free(array);
}
