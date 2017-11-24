typedef int DataType;
int n, t;
int * x;

int binarysearch(DataType t);

int binarysearch(DataType t) {
    int left, right, middle;
    left = 0;
    right = n - 1;

    while (left <= right) {
        middle = (left + right) / 2;
        /* printf("%d %d %d\n", left, middle, right); */
        if (x[middle] < t) left = middle + 1;
        else if (x[middle] == t) {
            return middle;
        }
        else right = middle - 1;
    }
    return -1;
}
