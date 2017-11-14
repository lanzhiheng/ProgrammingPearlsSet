#include <stdio.h>
#include <stdlib.h>

#define SIZE 10000000
#define BIT_OF_BYTE 8

void setInBitMap(long *, long, long);

void setInBitMap(long * targetArray, long row, long shift) {
    targetArray[row] |= 1 << shift;
}

int main() {
    long c[7] = {10000, 2201, 3000, 2, 4, 5, 64};

    // 测算需要分配多少字节的空间, 这里假设能够被8整除
    long mallocSize = SIZE / BIT_OF_BYTE;
    long *a = malloc(mallocSize);

    // 一个长整型有多少位
    long longSize = sizeof(long) * BIT_OF_BYTE;

    for (long i = 0; i < 7; i++) {
        long row = c[i] / longSize;
        long shift = c[i] % longSize;
        printf("%ld local at %ld, %ld\n", c[i], row, shift);
        setInBitMap(a, row, shift);
    }
    printf("%ld", a[1]);
}
