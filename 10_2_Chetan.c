/* Program to print Pascal's Triangle of n height */

#include<stdio.h>
void main() {
	int n;
	
	
	// Input height
	printf("Enter the height of Pascal's Triangle: ");
	scanf("%d",&n);
	
	// for loop to print rows of triangle
	for(int i=0;i<n;i++) {

		// initialization of first term in Pascal's Triangle
		int value=1;

		// for loop to print Spaces before values
		for(int j=0;j<n-i-1;j++)
			printf("  ");
		
		// for loop to Print Pascal Triangle's values
		for(int k=0;k<=i;k++) {
			printf("%d   ",value);
			value=value*(i-k)/(k+1);
		}
		
		printf("\n");
	}
}
