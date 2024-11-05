/* Program to check whether entered number is a part of Fibonacci Series or not */

#include<stdio.h>
int main() {
	int f0=0,f1=1,f2,n;
	
	
	// Taking Input Number
	printf("Enter any number to check whether it is a part of Fibonacci Series or Not : ");
	scanf("%d",&n);
	
	
	// Comparing with base condition
	if(n==0||n==1) {
		printf("%d is a part of the Fibonacci series",n);
		return 0;
	}
	
	// Initializing f2
	f2=f0+f1;
	while(f2<=n) {
	
		// Comparing f2 with n
		if(f2==n) {
			printf("%d is a part of the Fibonacci series",n);
			return 0;
			// Exit if Match Found
		}
		
		// Generating further series
		f0=f1;
		f1=f2;	
		f2=f0+f1;		
	}
	
	printf("%d is not a part of the Fibonacci series",n);
	return 0;
	// Exit if NO Match Found
}
