#include <stdio.h>

// Function to insert an element into an array
void insertElement(int arr[], int size, int position, int element) {
    // Shift elements to the right
    for (int i = size - 1; i >= position; i--) {
        arr[i + 1] = arr[i];
    }

    // Insert the element at the specified position
    arr[position] = element;
}

// Function to delete an element from an array
void deleteElement(int arr[], int size, int position) {
    // Shift elements to the left
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
}

// Function to search for an element in an array
int searchElement(int arr[], int size, int element) {
    // Iterate through the array and compare elements
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;  // Element found, return its index
        }
    }

    return -1;  // Element not found, return -1
}

int main() {
    int arr[100] = {1, 2, 3, 4, 5};
    int size = 5;

    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Insertion
    int insertPosition = 2;
    int insertElementValue = 10;
    insertElement(arr, size, insertPosition, insertElementValue);
    size++;  // Increase the size of the array

    printf("Array after insertion: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Deletion
    int deletePosition = 3;
    deleteElement(arr, size, deletePosition);
    size--;  // Decrease the size of the array

    printf("Array after deletion: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Searching
    int searchElementValue = 4;
    int searchResult = searchElement(arr, size, searchElementValue);

    if (searchResult != -1) {
        printf("Element found at index %d\n", searchResult);
    } else {
        printf("Element not found\n");
    }

    return 0;
}
