// Design, Develop and Implement a menu driven Program in C for the following operations on Binary Search
// Tree (BST) of Integers
// a. Create a BST of N Integers: 8, 10, 3, 1, 6, 14, 7
// a. Traverse the BST in Inorder
// b. Traverse the BST in Preorder
// c. Traverse the BST in and Post Order

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;  
    struct Node *right; 
};

struct Node* createNode(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct Node* insertElement(struct Node* root, int x) {
    if (root == NULL) {
        struct Node* temp = createNode(x);
        return temp;
    }
    if (root->data >= x) {
        root->left = insertElement(root->left, x);
    } else {
        root->right = insertElement(root->right, x);
    }
    return root;
}

void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node* root = NULL;
    
    root = insertElement(root, 8);
    root = insertElement(root, 10);
    root = insertElement(root, 3);
    root = insertElement(root, 1);
    root = insertElement(root, 6);
    root = insertElement(root, 14);
    root = insertElement(root, 7);
    
    printf("Inorder traversal:\n");
    inorder(root);
    printf("\nPreorder traversal:\n");
    preorder(root);
    printf("\nPostorder traversal:\n");
    postorder(root);
    
    return 0;
}