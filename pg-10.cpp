#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


void insertAtBeginning(struct Node** headRef, int newData);
void insertAtEnd(struct Node** headRef, int newData);
void deleteNode(struct Node** headRef, int key);
void displayList(struct Node* head);

int main() {
    struct Node* head = NULL; 

    
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);

    
    printf("Linked list after insertion at the beginning: ");
    displayList(head);

   
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);

   
    printf("Linked list after insertion at the end: ");
    displayList(head);

 
    deleteNode(&head, 20);

 
    printf("Linked list after deletion of node with value 20: ");
    displayList(head);

    return 0;
}


void insertAtBeginning(struct Node** headRef, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *headRef;
    *headRef = newNode;
}


void insertAtEnd(struct Node** headRef, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *headRef;
    newNode->data = newData;
    newNode->next = NULL;

    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
}


void deleteNode(struct Node** headRef, int key) {
    struct Node* temp = *headRef, *prev;

    
    if (temp != NULL && temp->data == key) {
        *headRef = temp->next;
        free(temp);
        return;
    }

    
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    
    if (temp == NULL) {
        printf("Node with key %d not found in the linked list.\n", key);
        return;
    }

    
    prev->next = temp->next;

    
    free(temp);
}


void displayList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
