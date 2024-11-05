/* Program to demonstrate Stack */

#include <stdio.h>

#define n 5

int arr[n], tos = -1, choice, x;


// Function Prototype
void push();
int pop();
void display();
void disp_num();

void main() {

	  // Menu Driven While Loop
    while (1) {
        printf("\n\n----------------- Stack Program -----------------");
        printf("\n1. Add Element to Stack (Push)\n");
        printf("2. Remove an Element from Stack (Pop)\n");
        printf("3. Display Elements in Stack\n");
        printf("4. Display Number of Elements in the Stack\n");
        printf("5. Exit\n");
        printf("Enter Your Choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                disp_num();
                break;
            case 5:
                return;
            default:
                printf("Wrong Choice.\n\n");
                break;
        }
    }
}

// Function to Insert Element in Stack
void push() {
    if (tos == n - 1) {
        printf("\n----- Stack is FULL! -----\n");
    } 
	else {
        printf("Enter an Element to Push: ");
        scanf("%d", &x);
        arr[++tos] = x;
        printf("Element %d pushed to stack.\n", x);
    }
}

// Function to Remove Element in Stack
int pop() {
    if (tos == -1) {
        printf("\n----- Stack is EMPTY! -----\n");
    } 
	else {
        printf("Successfully popped %d",arr[tos]);
        tos--;
    }
}

// Function to Display Elements in Stack
void display() {
    if (tos == -1) {
        printf("\nStack is EMPTY\n");
    }
    printf("\nStack Elements are:\n");
    for (int i = tos; i >= 0; i--) {
        printf("%d\n", arr[i]);
    }
}

// Function to Display Number of Elements
void disp_num() {
    printf("\nStack contains %d Elements\n", tos + 1);
}