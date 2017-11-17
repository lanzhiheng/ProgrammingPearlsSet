#include <time.h>
#include <stdio.h>
#include <stdlib.h>

unsigned long * sequenceArray(unsigned long);
void shuffleArray(unsigned long *, unsigned long);
unsigned long * generateShuffleArray(unsigned long);

// 生成指定长度的数组 5 -> [1, 2, 3, 4, 5]
unsigned long * sequenceArray(unsigned long length) {
    unsigned long sizeOfUnsignedLong = sizeof(unsigned long);
    unsigned long * sArray = malloc(sizeOfUnsignedLong * length);

    for (unsigned long i = 0; i < length; i ++) {
        sArray[i] = i + 1;
    }

    return sArray;
}

// 打乱传入数组的顺序
void shuffleArray(unsigned long * sArray, unsigned long length) {
    unsigned long shuffleTimes = length, temp, randomIndex1, randomIndex2;
    srand(time(NULL));

    for (unsigned long i = 0; i < shuffleTimes; i ++) {
        randomIndex1 = (unsigned long)rand() % length + 1L;
        randomIndex2 = (unsigned long)rand() % length + 1L;
        printf("%lu, %lu\n", randomIndex1, randomIndex2);
        temp = sArray[randomIndex1];
        sArray[randomIndex1] = sArray[randomIndex2];
        sArray[randomIndex2] = temp;
    }
    return ;
}

// 集成上面两个方法
unsigned long * generateShuffleArray(unsigned long length) {
    unsigned long * sArray = sequenceArray(length);
    shuffleArray(sArray, length);
    return sArray;
}



int main() {
    unsigned long length = 1000;
    unsigned long * s = generateShuffleArray(length);
    for (unsigned long i = 0; i < length; i ++) {
        printf("%lu\n", s[i]);
    }
}
