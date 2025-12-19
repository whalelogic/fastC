#include <stdio.h>  // Changed from <iostream>
#include "search/binary_search.h"


void reverse_array(int arr[], int size) {
    int start = 0;
    int end = size - 1;
    while (start < end) {
        // Swap arr[start] and arr[end]
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int arr[] = {5, 3, 4, 2, 1, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    reverse_array(arr, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");


    return 0;

}
