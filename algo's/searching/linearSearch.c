#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // Key found at index i
        }
    }
    return -1; // Key not found
}

int main() {
    int arr[] = {5, 8, 2, 15, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 15;

    int result = linearSearch(arr, n, key);

    if (result != -1) {
        printf("Key found at index %d\n", result);
    } else {
        printf("Key not found\n");
    }

    return 0;
}
