#include "./share.h"
#include "./binary_search.c"
#include "./binary_search_test.c"
#include "./timedriver.c"

int main() {
    /* timedriver(); */

    n = 100000;
    test_distinct_elements();
    test_same_elements();

    prepare_elements();
    sorted();
}
