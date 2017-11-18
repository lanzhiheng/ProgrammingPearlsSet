#include <time.h>
#include <stdio.h>
#include <stdlib.h>

unsigned long * sequenceArray(unsigned long);
void shuffleArray(unsigned long *, unsigned long);
unsigned long * generateShuffleArray(unsigned long);
void writeToFile (const char *, const unsigned long *, const unsigned long);

// generate new array with specific length
unsigned long * sequenceArray(unsigned long length) {
    unsigned long sizeOfUnsignedLong = sizeof(unsigned long);
    unsigned long * sArray = malloc(sizeOfUnsignedLong * length);
    for (unsigned long i = 0; i < length; i ++) {
        sArray[i] = i + 1;
    }

    return sArray;
}

// shuffle the order of the sArray
void shuffleArray(unsigned long * sArray, unsigned long length) {
    unsigned long shuffleTimes = length, temp, randomIndex1, randomIndex2;
    srand(time(NULL));

    for (unsigned long i = 0; i < shuffleTimes; i ++) {
        randomIndex1 = (unsigned long)rand() % length;
        randomIndex2 = (unsigned long)rand() % length;
        /* printf("%lu, %lu\n", randomIndex1, randomIndex2); */
        temp = sArray[randomIndex1];
        sArray[randomIndex1] = sArray[randomIndex2];
        sArray[randomIndex2] = temp;
    }
    return ;
}

// integrate `sequenceArray` and `shuffleArray` function
unsigned long * generateShuffleArray(unsigned long length) {
    unsigned long * sArray = sequenceArray(length);
    shuffleArray(sArray, length);
    return sArray;
}

// write array to file
void writeToFile (const char * filename, const unsigned long * array , const unsigned long length) {
    FILE * fp = fopen(filename, "w+");
    char str[21];

    for (unsigned long i = 0; i < length; i ++) {
        sprintf(str, "%lu\n", array[i]);
        fputs(str, fp);
    }
    fclose(fp);
}

int main() {
    unsigned long length = 1000;
    unsigned long * s = generateShuffleArray(length);
    writeToFile("./tmp/output", s, length);
    free(s);
}
