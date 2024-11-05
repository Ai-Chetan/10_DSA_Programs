/* Implementation of Binary Search. */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data); 
    } else {
        root->right = insert(root->right, data);
    }

    return root; 
}

int binarySearch(struct Node* root, int target) {
    if (root == NULL) {
        return -1; 
    }

    if (root->data == target) {
        return 1; 
    }

    if (target < root->data) {
        return binarySearch(root->left, target);
    }
    
    return binarySearch(root->right, target);
}

int main() {
    int size;
    
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    struct Node* root = NULL; 

    printf("Enter %d numbers: ", size);
    for (int i = 0; i < size; i++) {
        int num;
        scanf("%d", &num);
        root = insert(root, num); 
    }

    int target;
    printf("Enter the number to search: ");
    scanf("%d", &target);

    int result = binarySearch(root, target);
    if (result != -1) {
        printf("Element found.\n");
    } else {
        printf("Element not found.\n");
    }
    return 0;
}