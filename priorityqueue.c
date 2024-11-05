/* Program to demonstrate Linked List based Priority Queue */

#include <stdio.h>
#include <stdlib.h>

int x, p;
int choice;

struct node {
    int info;
    int priority;
    struct node* next;
};
struct node* list = NULL;

struct node* getnode() {
    return ((struct node*)malloc(sizeof(struct node)));
}

void freenode(struct node* p) {
    free(p);
}

// Insert based on priority
void priorityorder(int x, int p) {
    struct node* newnode, * temp, * prev;
    newnode = getnode();
    newnode->info = x;
    newnode->priority = p;
    newnode->next = NULL;

    if (list == NULL || list->priority > p) {
        // If the queue is empty or the new node has higher priority than the first node
        newnode->next = list;
        list = newnode;
    } else {
        // Traverse the queue and find the correct position to insert
        temp = list;
        while (temp->next != NULL && temp->next->priority <= p) {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

// Delete the first element 
void dequeue() {
    struct node* temp;
    if (list == NULL) {
        printf("\nPriority Queue is EMPTY!\n");
    } else {
        temp = list;
        printf("%d with priority %d is deleted\n", temp->info, temp->priority);
        list = list->next;
        freenode(temp);
    }
}

// Display the priority queue
void display() {
    struct node* temp;
    if (list == NULL) {
        printf("\nPriority Queue is EMPTY!\n");
    } else {
        temp = list;
        printf("\nPriority Queue:\n\n");
        printf("--------------------\n");
        printf("Info \t Priority\n");
        printf("--------------------\n");
        while (temp != NULL) {
            printf("  %d \t   %d\n", temp->info, temp->priority);
            temp = temp->next;
        }
        printf("--------------------\n");
    }
}

void main() {
    // Menu-driven while loop
    while (1) {
        printf("\n\n------- Linked List based Priority Queue Program -------\n");
        printf("\n1. Add Element in Priority Queue");
        printf("\n2. Remove Element with Highest Priority");
        printf("\n3. Display");
        printf("\n4. Exit\n");
        printf("\nEnter Your Choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Element to add: ");
                scanf("%d", &x);
                printf("Enter its Priority: ");
                scanf("%d", &p);
                priorityorder(x, p);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);
                break;

            default:
                printf("Wrong Choice.\n\n");
                break;
        }
    }
}