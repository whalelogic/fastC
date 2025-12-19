#include "stdio.h"

// Binary Search
int binarySort(int a[], int n) {
    for (int i = 1; i < n; ++i) {
        int j = i - 1;
        int key = a[i];

        int pos = binarySearch(a, key, 0, j);

        while (j >= pos) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
    return 0;
}

