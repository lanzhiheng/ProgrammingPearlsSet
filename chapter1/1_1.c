#include <stdio.h>

void bubbleSort(int * array, int len);
void printArray(int * array, int length);

void bubbleSort(int * array, int len) {
  int i, j;
  int temp;

  for (i = 0; i < len; i++) {
    for (j = i; j < len; j ++) {
      if (array[j] < array[i]) {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }
  }
}

void printArray(int * array, int length) {
  int i;
  for (i = 0; i < length; i ++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

int main() {
  int LENGTH = 10;
  int array[] = {100, 110, 20, 30, 10, 1000, 3, 4, 1, 2};
  printArray(array, LENGTH);
  bubbleSort(array, LENGTH);
  printArray(array, LENGTH);
}
