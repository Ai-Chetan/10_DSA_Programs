/* Program to demonstrate Circular Queue */

#include<stdio.h>
#define n 5

int arr[n], f=-1, r=-1, choice, x, counter;

// Function Prototype
void Enqueue(int x);
int Dequeue();
void display();

int main() {

	// Menu Driven While Loop
    while(1) {
        printf("\n\n----------------- Circular Queue Program -----------------");
        printf("\n1. Add Element to Queue (Enqueue)\n");
        printf("2. Remove an Element from Queue (Dequeue)\n");
        printf("3. Display Elements in Queue\n");
        printf("4. Exit\n");
        printf("Enter Your Choice : ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter Element to add in Queue: ");
                scanf("%d", &x);
                Enqueue(x);
                break;
                
            case 2:
                Dequeue();
                break;    
                
            case 3:
                display();
                break;
                
            case 4:
                return 0;
                
            default: 
                printf("Wrong Choice.\n\n");
                break;
        }
    }
}

// Function to Insert Element from Back
void Enqueue(int x) {
    if (f==(r+1)%n) {
        printf("\n-----Queue is FULL!-----\n");
    }
    else {
        if (f == -1 && r == -1) {
            f = 0;
            r = 0;
        }
        else {
            r = (r + 1) % n;
        }
       arr[r] = x;  
    }
}

// Function to Remove Element from Front
int Dequeue() {
    if (f == -1 && r == -1) {
        printf("\n-----Queue is EMPTY!-----\n");
    }
    else {
        printf("Successfully Dequeued %d \n", arr[f]);
        if (f == r) {
            f = -1;
            r = -1;
        }
        else {
            f = (f + 1) % n;
        }
    }
}

// Function to Display Queue Elements 
void display() {
    if (f == -1 && r == -1) {
        printf("\nQueue is EMPTY\n");
    }
    else {
        printf("\nQueue Elements are \n");
        for (int i = f; i != r % n ; i = (i + 1) % n) {
            printf("%d\n", arr[i]);
        }
        printf("%d\n", arr[r]);
    }
}

