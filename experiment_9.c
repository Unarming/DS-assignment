// Design, Develop and Implement a menu driven Program in C/C++ for the following operations on Doubly
// Linked List (DLL)
// a. Create a DLL.
// b. Print all the elements in DLL in forward traversal order
// c. Print all elements in DLL in reverse traversal order
// d. Exit

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL; 

struct Node* GetNewNode(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void InsertAtHead(int x) {
    struct Node* newNode = GetNewNode(x);
    if (head == NULL) {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void InsertAtTail(int x) {
    struct Node* temp = head;
    struct Node* newNode = GetNewNode(x);
    if (head == NULL) {
        head = newNode;
        return;
    }
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void Print() {
    struct Node* temp = head;
    printf("Forward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void ReversePrint() {
    struct Node* temp = head;
    if (temp == NULL) return; 

    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("Reverse: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    head = NULL; 

    InsertAtTail(2); Print(); ReversePrint();
    InsertAtTail(4); Print(); ReversePrint();
    InsertAtTail(6); Print(); ReversePrint();
    InsertAtHead(1); Print(); ReversePrint();
    InsertAtHead(9); Print(); ReversePrint();

    return 0;
}