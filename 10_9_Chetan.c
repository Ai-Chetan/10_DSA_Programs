/* Program to print Unique Elements in an Array */

#include <stdio.h>

void main() {
    int arr[10], n, counter = 0;
	
	// Input length of Array
    printf("Enter Number of elements in an Array (Max 10): ");
    scanf("%d", &n);

	// Scanning n Array Elements 
    printf("Enter %d elements of an Array: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Unique Elements are \n");
    
    // Using Nested for loop to compare each array element with all others
    for (int i = 0; i < n; i++) {
        int unique = 1;

        for (int j = 0; j < n; j++) {
            if (i != j && arr[i] == arr[j]) {
                unique = 0;
                break;
            }
        }
		
        if (unique) {
            printf("%d\n", arr[i]);
        }
    }
}
