/* Program to implement Bubble or Selection Sort */

#include <stdio.h>

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size, choice;

    printf("1.Sorting using Bubble Sort\n2.Sorting using Selection Sort\nEnter your choice: ");
    scanf("%d", &choice);
    
    printf("\nEnter the number of elements: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter %d numbers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    printArray(arr, size);

    if (choice == 1) {
    bubbleSort(arr, size);
    printf("Sorted array (Bubble Sort): ");
    printArray(arr, size);
    }
    else if (choice == 2) {
    selectionSort(arr, size);
    printf("Sorted array (Selection Sort): ");
    printArray(arr, size);
    }
    else {
        printf("Wrong Choice!");
    }
    return 0;
}
