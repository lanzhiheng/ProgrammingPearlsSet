#include <stdio.h>
#include <stdlib.h>

#define SIZE 10000000
#define BIT_OF_BYTE 8

void setInBitMap(unsigned long *, unsigned long, unsigned long);
unsigned long * bitMapSort(unsigned long*, unsigned long);
void travalBit(unsigned long *, unsigned long);

void travalBit(unsigned long * number, unsigned long len) {
    // 一个长整型有多少位
    unsigned long k = 1L;
    unsigned long longSize = sizeof(unsigned long) * BIT_OF_BYTE;
    for (unsigned long i = 0; i < len; i ++) {
        for (unsigned long j = 0; j <  longSize; j ++) {
            k = 1;
            if ((number[i] & (k << j)) != 0) {
                printf("%lu\n", longSize * i + j + 1);
            }
        }
    }
}

unsigned long * bitMapSort(unsigned long * inputArray, unsigned long length) {
    // 测算需要分配多少字节的空间, 这里假设能够被8整除
    unsigned long mallocSize = SIZE / BIT_OF_BYTE;
    unsigned long *a = malloc(mallocSize);
    // 一个长整型有多少位
    unsigned long longSize = sizeof(unsigned long) * BIT_OF_BYTE;

    for (unsigned long i = 0; i < length; i++) {
        unsigned long row = (inputArray[i] - 1) / longSize;
        unsigned long shift = (inputArray[i] - 1) %  longSize;
        /* printf("%ld local at %ld, %ld\n", inputArray[i], row, shift); */
        setInBitMap(a, row, shift);
    }

    return a;
}

void setInBitMap(unsigned long * targetArray, unsigned long row, unsigned long shift) {
    targetArray[row] |= 1L << shift ;
}

int main() {
    unsigned long c[7] = {1, 10000, 2201, 3000, 2, 4, 5};
    unsigned long * m = bitMapSort(c, 7);
    travalBit(m, 1000);
}
