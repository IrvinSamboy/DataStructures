#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    if(!newNode){
        printf("Error: An error occurred while allocating memory space.");
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void append(Node** head, int data){
    Node* newNode = createNode(data);

    if(*head == NULL){
        *head = newNode;
        return;
    }

    Node* currentNode = *head;

    while (currentNode->next != NULL)
    {
        currentNode = currentNode->next;
    }
    currentNode->next = newNode;
}

void prepend(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void add(Node* head, int data, int beforeValue) {
    Node* newNode = createNode(data);

    Node* currentNode = head;
    while (currentNode != NULL && currentNode->data != beforeValue)
    {
        currentNode = currentNode->next;
    }
    
    if(currentNode == NULL) {
        return;
    }

    newNode->next = currentNode->next;
    currentNode->next = newNode;
}

void delete(Node** head, int value) {
    Node* currentNode = *head;
    Node* previousNode = NULL;
    while (currentNode != NULL && currentNode->data != value) {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }

    if (currentNode == NULL) {
        return;
    }

    if (previousNode == NULL) {
        *head = currentNode->next;
    } 
    
    else {
        previousNode->next = currentNode->next;
    }
    
}

void printList(Node* head){
    Node* currentList = head;
    while (currentList != NULL)
    {
        printf("%d -> ", currentList->data);
        currentList = currentList->next;
    }
    printf("NULL \n");
}

void freeList(Node* head){
    Node* tempList = NULL;
    while (head != NULL)
    {
        tempList = head;
        head=head->next;
        free(tempList);
    }
    
}

int main(){
    Node* head = NULL;

    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);
    append(&head, 50);

    printList(head);

    prepend(&head, 80);

    printf("List prepend \n");
    printList(head);

    add(head, 99, 40);
    printf("List add \n");
    printList(head);

    delete(&head, 99);
    printf("List delete \n");
    printList(head);

    delete(&head, 80);
    printf("List delete head \n");
    printList(head);

    freeList(head);

    return 0;
}