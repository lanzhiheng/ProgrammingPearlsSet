#include "./binary_search.c"
#define s binarysearch

void test_distinct_elements();
void test_same_elements();
int sorted();

int sorted() {
    int i;
    for (i = 0; i < n - 1; i++) {
        if (x[i] > x[i+1]) return 0;
    }
    return 1;
}

void test_distinct_elements() {
    int i;
    x = malloc(sizeof(int) * n);
    for (i = 0; i < n; i ++) {
        x[i] = 10 * i;
    }

    for (i = 0; i < n; i ++) {
        assert(s(10 * i) == i);
        assert(s(10 * i - 5) == -1);
    }
    assert(s(10 * n - 5) == -1);
    assert(s(10 * n) == -1);
    free(x);
}

void test_same_elements() {
    int i;
    x = malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) x[i] = 10;
    if (n == 0) assert(s(10) == -1);
    else assert(0 <= s(10) && s(10) < n);
    assert(s(5) == -1);
    assert(s(15) == -1);
    free(x);
}

int main() {
    n = 1000;
    test_distinct_elements();
    test_same_elements();

    while(scanf("%d %d", &n, &t) != EOF) {
        x = malloc(sizeof(int) * n);
        for (int i = 0; i < n; i ++) {
            x[i] = 10 * i;
        }
        assert(sorted());
        printf("%d\n", binarysearch(t));
    }
}
