/* Program to print the number of Duplicate Elements in an Array */

#include <stdio.h>

void main() {
    int arr[10], n, counter = 0;
	
	// Input length of Array
    printf("Enter Number of elements in an Array (Max 10): ");
    scanf("%d", &n);

    printf("Enter %d elements of an Array: ", n);
    
    // Scanning n Array Elements 
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
	
	// Comparint Array Elements with each other
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                counter++;
                break;
            }
        }
    }
    printf("Number of Duplicate Elements in the Array is %d ", counter);
}
