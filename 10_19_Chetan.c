/* Implementation of operations (Insetion, Search, Counting of nodes, Count of leaf nodes etc.) in a binary search tree */

#include<stdio.h>
#include<stdlib.h>

struct bt {
	int info;
	struct bt *left;
	struct bt *right;
};

struct bt *root = NULL; 
struct bt *newnode;


int nodes = 0, leafnodes = 0, c,x; 

struct bt* getnode();
void insert(struct bt *r,int x);
void inorder(struct bt *r);
void preorder(struct bt *r);
void postorder(struct bt *r);
int search(struct bt *r,int x);
void countnodes(struct bt *r);
void countleafnodes(struct bt *r);

void main() {

	while(1) {
		printf("\n\n-------------Tree Operations-------------\n\n");
		printf("1. Insert\n");
		printf("2. Inorder\n");
		printf("3. Preorder\n");
		printf("4. Postorder\n");
		printf("5. Search\n");
		printf("6. Count number of nodes\n");
		printf("7. Count number of leaf nodes\n");
		printf("8. Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&c);
		
		switch(c) {
			case 1 : 
                printf("\nEnter element to be inserted : ");
				scanf("%d",&x);
				if(root == NULL) {
					newnode = getnode();
					newnode -> info = x;
					newnode -> left = NULL;
					newnode -> right = NULL;
					root = newnode;
				}
				else 
					insert(root,x);
				break;
				
			case 2 : 
			    if (root == NULL) 
                printf("\nTree is empty\n");
                else 
                inorder(root);
				break;
				
			case 3 : 
			    if (root == NULL) 
                 printf("\nTree is empty\n");
                else 
                preorder(root);
				break;
				
			case 4 : 
			    if (root == NULL) 
                printf("\nTree is empty\n");
                else 
                postorder(root);
				break;
				
			case 5 : 
                printf("\nEnter element that you want to search : ");
				scanf("%d",&x);
				search(root,x);
				break;
				
			case 6 : 
                countnodes(root);
			    printf("\nThere are %d nodes\n",nodes);
			    nodes = 0;
			    break;
			    
			case 7 : 
                countleafnodes(root);
			    printf("\nThere are %d leaf nodes\n",leafnodes);
			    leafnodes = 0;
			    break;
				
			case 8 : 
                exit(1);
				break;
				
			default : 
                printf("\nInvalid input\n");
				break;
		} 
	} 
}

struct bt* getnode() {
	return ((struct bt*)malloc(sizeof(struct bt))); 
}

void insert(struct bt *r,int x) {
	if(x == r->info) {
		printf("\nDuplicate entries\n");
	}
	else if(x < r->info) {
		if(r->left == NULL)	{
			newnode = getnode();
			newnode ->info = x;
			newnode -> left = NULL;
			newnode -> right = NULL;
			r->left = newnode;
		}
		else {
			insert(r->left,x);
		}
	}
	else if(x > r->info) {
		if(r->right == NULL) {
			newnode = getnode();
			newnode -> info = x;
			newnode -> left = NULL;
			newnode -> right = NULL;
			r->right = newnode;
		}
		else {
			insert(r->right,x);
		}
	}
} 

void inorder(struct bt *r) {
	if(r !=NULL ) {
		inorder(r->left);
		printf("%d\t",r->info);
		inorder(r->right);
	}
} 

void preorder(struct bt *r) {
	if(r != NULL) {
		printf("%d\t",r->info);
		preorder(r->left);
		preorder(r->right);
	}
} 

void postorder(struct bt *r) {
	if(r != NULL) {
		postorder(r->left);
		postorder(r->right);
		printf("%d\t",r->info);
	}
} 

int search(struct bt *r,int x) {
	int f = 0;
	if (r == NULL) 
                printf("\nTree is empty\n");
	else if(r!=NULL) {
		if( x == r->info) {
			printf("%d found\n",r->info);
			return 1;
		}
		else if( x < r->info) {
			f=search(r->left,x);
			return f;
		}
		else if(x > r->info) {
			f=search(r->right,x);
			return f;
		}
	}
	if(f==0) {
		printf("\nElement not found\n");
	}
}

void countnodes(struct bt *r) {
    if(r != NULL) {
        nodes++;
        countnodes(r -> left);
        countnodes(r -> right);
    }
} 

void countleafnodes(struct bt *r) {
    if(r != NULL) {
        if(r -> left == NULL && r -> right == NULL) {
            leafnodes++;
        }
        countleafnodes(r -> left);
        countleafnodes(r -> right);
    }
} 