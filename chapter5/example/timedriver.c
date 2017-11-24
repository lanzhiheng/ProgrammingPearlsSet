#define s binarysearch

clock_t starttime, endtime, clicks;

void timedriver();

void timedriver() {
    int numtests, i, j;
    double time_spend;

    while(scanf("%d %d", &n, &numtests) != EOF) {
        x = malloc(sizeof(int) * n);
        for (i = 0; i < n; i ++) {
            x[i] = 10 * i;
        }

        starttime = clock();
        for (i = 0; i < numtests; i ++) {
            for (j = 0; j < n; j ++) {
                assert(s(x[j]) == j);
            }
        }
        endtime = clock();
        time_spend = (double)(endtime - starttime) / CLOCKS_PER_SEC;

        printf("%d %d %lf\n", n, numtests, time_spend);
    }
}
