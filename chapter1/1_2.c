#include <stdio.h>
#include <stdlib.h>

#define SIZE 10000000L
#define BIT_OF_BYTE 8L

typedef unsigned long BitmapChunk;

void setInBitMap(BitmapChunk *, unsigned long, unsigned long);
unsigned long * bitMapSort(unsigned long*, unsigned long);
void travalBit(BitmapChunk *, unsigned long);

// 该函数用于在位图阵列中对应的位置置1
void setInBitMap(BitmapChunk * targetArray, unsigned long row, unsigned long shift) {
    // 1必须是长整型，不然位移的时候会溢出
    BitmapChunk initNumber = 1L;
    targetArray[row] |= initNumber << shift ;
}

unsigned long * bitMapSort(unsigned long * inputArray, unsigned long length) {
    // 测算需要分配多少字节的空间, 这里假设能够被8整除
    // TODO: 需要动态检测分配多少内存，而不要写死
    unsigned long mallocSize = SIZE / BIT_OF_BYTE;
    BitmapChunk *bitmap = malloc(mallocSize);

    // 一个簇有多少位
    unsigned long bitOfBitmapChuck = sizeof(BitmapChunk) * BIT_OF_BYTE;
    unsigned long subtractOne, row, shift;

    for (unsigned long i = 0L; i < length; i++) {
        subtractOne = inputArray[i] - 1L;
        row = subtractOne / bitOfBitmapChuck;
        shift = subtractOne %  bitOfBitmapChuck;
        // printf("%ld local at %ld, %ld\n", inputArray[i], row, shift);

        setInBitMap(bitmap, row, shift);
    }

    return bitmap;
}

void travalBit(BitmapChunk * number, unsigned long len) {
    // 一个长整型有多少位
    BitmapChunk k = 1L, reset = 1L;
    unsigned long longSize = sizeof(BitmapChunk) * BIT_OF_BYTE;
    for (unsigned long i = 0L; i < len; i ++) {
        for (unsigned long j = 0L; j <  longSize; j ++) {
            k = reset;
            if ((number[i] & (k << j)) != 0L) {
                // 打印无符号长整型
                printf("%lu\n", longSize * i + j + 1L);
            }
        }
    }
}

int main() {
    unsigned long c[8] = {1, 10000, 2201, 3000, 2, 4, 5, 64};
    unsigned long * m = bitMapSort(c, 8);
    travalBit(m, 100);
}
