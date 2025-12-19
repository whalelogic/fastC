#include <stdio.h>  

// Binary Search 
int binarySearch(int a[], int item, int low, int high) {
    if (high <= low) {
        return (item > a[low]) ? (low + 1) : low;
    }

    int mid = (low + high) / 2;

    if (item == a[mid])
        return mid + 1;

    if (item > a[mid])
        return binarySearch(a, item, mid + 1, high);

    return binarySearch(a, item, low, mid - 1);
}

// Binary Sort 
void binarySort(int a[], int n) {
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
}


