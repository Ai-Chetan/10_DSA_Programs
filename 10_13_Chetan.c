/* Program to demonstrate Circular Queue */

#include<stdio.h>
#define n 5

int arr[n], f=-1, r=-1, choice, x, counter;

// Function Prototype
void REnqueue();
int FDequeue();
void FEnqueue();
int RDequeue();
void display();

int main() {

    // Menu Driven While Loop
    while(1) {
        printf("\n\n----------------- Circular Queue Program -----------------");
        printf("\n1. Add Element to Queue (REnqueue)\n");
        printf("2. Remove an Element from Queue (FDequeue)\n");
        printf("3. Add Element to Queue (FEnqueue)\n");
        printf("4. Remove an Element from Queue (RDequeue)\n");
        printf("5. Display Elements in Queue\n");
        printf("6. Exit\n");
        printf("Enter Your Choice : ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                REnqueue();
                break;
                
            case 2:
                FDequeue();
                break;
                
            case 3:
                FEnqueue();
                break;
                
            case 4:
                RDequeue();
                break;
                
            case 5:
                display();
                break;
                
            case 6:
                return 0;
                
            default: 
                printf("Wrong Choice.\n\n");
                break;
        }
    }
}

// Function to Insert Element from Back
void REnqueue() {
    if (f==(r+1)%n) {
        printf("\n-----Queue is FULL!-----\n");
    }
    else {
        printf("Enter Element to add in Queue: ");
        scanf("%d", &x);
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
int FDequeue() {
    if (f == -1 && r == -1) {
        printf("\n-----Queue is EMPTY!-----\n");
        return -1;
    }
    else {
        int dequeued = arr[f];
        printf("Successfully Dequeued %d \n", dequeued);
        if (f == r) {
            f = -1;
            r = -1;
        }
        else {
            f = (f + 1) % n;
        }
        return dequeued;
    }
}

// Function to Insert Element from Front
void FEnqueue() {
    if ((f==(r+1)%n) || (r==(f+1)%n)) {
        printf("\n-----Queue is FULL!-----\n");
    }
    else {
        printf("Enter Element to add in Queue: ");
        scanf("%d", &x);
        if (f == -1 && r == -1) {
            f = 0;
            r = 0;
        }
        else {
            f = (n + f - 1) % n;
        }
       arr[f] = x;  
    }
}

// Function to Remove Element from Back
int RDequeue() {
    if (f == -1 && r == -1) {
        printf("\n-----Queue is EMPTY!-----\n");
        return -1;
    }
    else {
        int dequeued = arr[r];
        printf("Successfully Dequeued %d \n", dequeued);
        if (f == r) {
            f = -1;
            r = -1;
        }
        else {
            r = (r - 1 + n) % n;
        }
        return dequeued;
    }
}

// Function to Display Queue Elements 
void display() {
    if (f == -1 && r == -1) {
        printf("\nQueue is EMPTY\n");
    }
    else {
        printf("\nQueue Elements are \n");
        for (int i = f; i != r ; i = (i + 1) % n) {
            printf("%d\t", arr[i]);
        }
        printf("%d", arr[r]);
    }
}