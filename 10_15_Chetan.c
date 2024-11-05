/* Program to demonstrate Linked List based Stack */

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

void insertatbeg (int x) {
	struct node * newnode;
	newnode = getnode();
	newnode -> info = x;
	newnode -> next = list;
	list = newnode;
}

void deleteatbeg () {
	struct node *temp;
	temp = list;
	if (list == NULL) {
		printf("\nStack is EMPTY!");
	}
	else {
		printf("%d is deleted", temp -> info);
		list = list -> next;
		freenode(temp);
	}
}


void display() {
	struct node *temp;
	temp = list;
	if (list == NULL) {
		printf("\nStack is EMPTY!");
	}
	else {
		while(temp != NULL) {
			printf("%d\n", temp -> info);
			temp = temp -> next;
		}
	}
}

void main() {
	// Menu Driven While Loop
        while(1) {
        	printf("\n\n------- Linked List based Stack Program -------\n");
        	printf("\n1. Add Element in Stack");
        	printf("\n2. Remove Element from Stack");
        	printf("\n3. Display");
        	printf("\n4. Exit\n");
        	printf("\nEnter Your Choice : ");
        	scanf("%d", &choice);

        	switch(choice) {
        		case 1:
               	printf("Enter Element to add: ");
               	scanf("%d", &x);
               	insertatbeg(x);
               	break;
               	
               	case 2:
               	deleteatbeg();
               	break;
               	
               	case 3:
                	display();
                	break;
                
            		case 4:
               	return;
               	break;
                
                       default: 
                       printf("Wrong Choice.\n\n");
                       break;
		}
	}
}
























