#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid; // Key found at index mid
        }

        if (arr[mid] < key) {
            low = mid + 1; // Key may be present in the right half
        } else {
            high = mid - 1; // Key may be present in the left half
        }
    }

    return -1; // Key not found
}

int main() {
    int arr[] = {2, 5, 8, 10, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 15;

    int result = binarySearch(arr, 0, n - 1, key);

    if (result != -1) {
        printf("Key found at index %d\n", result);
    } else {
        printf("Key not found\n");
    }

    return 0;
}
