/* Program to demonstrate insert, delete, display, search in Linked List */

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

void insertatend (int x) {
	struct node *newnode, *temp, *rear;
	newnode = getnode();
	newnode -> info = x;
	newnode -> next = NULL;
	temp = list;
	if(temp == NULL) {
		list = newnode;
	}
	else {
		while(temp -> next != NULL) {
			temp = temp -> next;
		}
		temp -> next = newnode;
		rear = newnode;
	}
}

void insertatloc (int x, int p) {
	struct node *newnode, *temp;
	newnode = getnode();
	newnode -> info = x;
	newnode -> next = NULL;
	temp = list;
	if (temp == NULL) {
		newnode -> next = NULL;
		list = newnode;
	}
	else {
		for (int i=1 ; i<p-1 ; i++) {
			
			if(temp -> next == NULL) {
				printf("Location is out of Scope, Adding Element at the End");
				temp -> next = newnode;
				break;
			}
			
			temp = temp -> next;
		}
		newnode -> next = temp -> next;
		temp -> next = newnode;
	}
}

void deleteatbeg () {
	struct node *temp;
	temp = list;
	if (list == NULL) {
		printf("\nLinked List is EMPTY!");
	}
	else {
		printf("%d is deleted", temp -> info);
		list = list -> next;
		freenode(temp);
	}
}

void deleteatend() {
	struct node *temp, *ptr;
	temp = list;
	if(list == NULL) {
		printf("\nLinked List is EMPTY!");
	}
	else {
		if (temp -> next == NULL) {
			printf("\n%d is deleted", temp -> info);
			list = list -> next;
			freenode(temp);
		}
		else {
			while (temp -> next != NULL) {
				ptr = temp;
				temp = temp -> next;
			}
			printf("\n%d is deleted", temp -> info);
			ptr -> next = NULL;
			freenode(temp);
		}
	}
}

void deleteatloc (int p) {
	struct node *temp, *ptr;
	temp = list;
	if (temp == NULL) {
		printf("\nLinked List is EMPTY!");
	}
	else {
		if (p==1) {
			printf("\n%d is deleted", temp -> info);
			list = temp -> next;
			freenode(temp);
		}
		else {
			for (int i=1 ; i<p ; i++) {
				ptr = temp;
				temp = temp -> next;
			}
			printf("\n%d is deleted", temp -> info);
			ptr -> next = temp -> next;
			freenode(temp);
		}
	}
}

void display() {
	struct node *temp;
	temp = list;
	if (list == NULL) {
		printf("\nLinked List is EMPTY!");
	}
	else {
		while(temp != NULL) {
			printf(" %d ", temp -> info);
			temp = temp -> next;
		}
	}
}

void search() {
	int x, ctr=0, isFound = 0;
	struct node *temp;
	printf("\nEnter an Element to Search: ");
	scanf("%d",&x);
	temp = list;
	if (list == NULL) {
		printf("\nLinked List is EMPTY!");
	}
	else {
		while(temp != NULL) {
			ctr++;
			if(temp -> info == x) {
				isFound=1;
				break;
			}
			temp = temp -> next;
		}
	}
	isFound ? printf("\nElement found at %d location",ctr) : printf("\nElement not Found!");
	
}

void main() {
	// Menu Driven While Loop
        while(1) {
        	printf("\n\n------- Linked Lists Program -------\n");
        	printf("\n1. Add Element insert at beginning");
        	printf("\n2. Add Element insert at end");
        	printf("\n3. Add Element insert at location");
        	printf("\n4. Delete at beginning");
        	printf("\n5. Delete at end");
        	printf("\n6. Delete at location");
        	printf("\n7. Display");
        	printf("\n8. Search in Linked List");
        	printf("\n9. Exit\n");
        	printf("\nEnter Your Choice : ");
        	scanf("%d", &choice);

        	switch(choice) {
        		case 1:
               	printf("Enter Element to add: ");
               	scanf("%d", &x);
               	insertatbeg(x);
               	break;
               	
               	case 2:
               	printf("Enter Element to add: ");
               	scanf("%d", &x);
               	insertatend(x);
               	break;
               	
               	case 3:
               	printf("Enter Element to add: ");
               	scanf("%d", &x);
               	printf("Enter the Position to Add Element: ");
               	scanf("%d", &p);
               	insertatloc(x, p);
               	break;
                	
                	case 4:
               	deleteatbeg();
               	break;
               	
               	case 5:
               	deleteatend();
               	break;
               	
               	case 6:
               	printf("Enter the Position to Delete Element: ");
            		scanf("%d", &p);
            		deleteatloc(p);
               	break;
                
            		case 7:
                	display();
                	break;
                	
                	case 8:
                	search();
                	break;
                
            		case 9:
               	return;
               	break;
                
                       default: 
                       printf("Wrong Choice.\n\n");
                       break;
		}
	}
}

























