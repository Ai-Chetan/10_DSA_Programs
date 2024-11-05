/* Program to demonstrate Linked List based Queue */

#include<stdio.h>
#include<stdlib.h>

int x, p;
int choice;

struct node {
	int info;
	struct node *next;
};
struct node *list = NULL;

struct node *getnode() {
	return ((struct node *) malloc (sizeof(struct node)));
}

void freenode(struct node * p) {
	free(p);
}

void insertatend(int x) {
	struct node *newnode, *temp;
	newnode = getnode();
	newnode->info = x;
	newnode->next = NULL;

	if (list == NULL) {
		list = newnode;
	} else {
		temp = list;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newnode;
	}
}

void deleteatbeg() {
	struct node *temp;
	if (list == NULL) {
		printf("\nQueue is EMPTY!\n");
	} else {
		temp = list;
		printf("%d is deleted\n", temp->info);
		list = list->next;
		freenode(temp);
	}
}

void display() {
	struct node *temp;
	if (list == NULL) {
		printf("\nQueue is EMPTY!\n");
	} else {
		temp = list;
		printf("Queue: ");
		while (temp != NULL) {
			printf("%d ", temp->info);
			temp = temp->next;
		}
		printf("\n");
	}
}

void main() {
	// Menu Driven While Loop
        while(1) {
        	printf("\n\n------- Linked List based Queue Program -------\n");
        	printf("\n1. Add Element in Queue");
        	printf("\n2. Remove Element from Queue");
        	printf("\n3. Display");
        	printf("\n4. Exit\n");
        	printf("\nEnter Your Choice : ");
        	scanf("%d", &choice);

        	switch(choice) {
        		case 1:
               	printf("Enter Element to add: ");
               	scanf("%d", &x);
               	insertatend(x);
               	break;
               	
               	case 2:
               	deleteatbeg();
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
