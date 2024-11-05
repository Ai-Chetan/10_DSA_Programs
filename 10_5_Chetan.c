/* Program to find the Largest Element in an Array */

#include <stdio.h>

void main() {
    
    int a[5],largest;
    printf("Enter array of 5 elements:\n");
    
    // Input 5 array elements
    for (int i = 0; i < 5; i++) 
    	scanf("%d",&a[i]);
    largest = a[0];
        
    // Comparing every element with each other
    for (int i = 0; i < 5-1; i++) {
        for (int j = 0; j < 5-i-1; j++) {
            
            // Assigning largest = largest element in array
            if (largest < a[j+1])          
            	largest = a[j+1];
        }
    }

    printf("\nLargest Element is :  %d\n",largest);
}

