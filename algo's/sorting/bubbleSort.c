#include <stdio.h>

void bubbleSort(int array[], int size){
    int i, j;
    for (i = 0; i < size - 1; i++){

        for (j = 0; j < size - i - 1; j++){
            
            if (array[j] > array[j + 1]){
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void printArray(int array[], int size){
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int array[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(array) / sizeof(array[0]);

    printf("Original array: ");
    printArray(array, size);

    bubbleSort(array, size);

    printf("Sorted array: ");
    printArray(array, size);

    return 0;
}