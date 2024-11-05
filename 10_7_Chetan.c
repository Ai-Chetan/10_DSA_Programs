/* Program to Compare two Arrays */

#include<stdio.h>

int main() {

	int n,a[10],b[10];


	// Input length of Array
	printf("Enter number of  array Elements (max 10): ");
	scanf("%d",&n);

	printf("Enter First array Elements: ");

	// Scanning 5 Array Elements in 1st Array
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);

	printf("Enter Second array Elements: ");

	// Scanning 5 Array Elements in 2nd Array
	for(int i=0;i<n;i++)
		scanf("%d",&b[i]);

	// Comapring Both Arrays
	for(int i=0;i<n;i++) {
 		if (a[i]!=b[i]) {
 			printf("Array is Unidentical");
 			return 0;
 			// Exit if Array is Unidentical
 		}
	}

	printf("Array is Identical");
 	return 1;
 	// Exit if Array is Identical
}
