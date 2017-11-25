#define s binarysearch

void test_distinct_elements();
void test_same_elements();
int sorted();
void prepare_elements();

int sorted() {
    int i;
    for (i = 0; i < n - 1; i++) {

        // Add x[i] > x[n - 1] for fail fast
        if (x[i] > x[i+1] || x[i] > x[n - 1]) return 0;
    }
    return 1;
}

void prepare_elements() {
    int i;
    x = malloc(sizeof(int) * n);
    for (i = 0; i < n; i ++) {
        x[i] = 10 * i;
    }
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
