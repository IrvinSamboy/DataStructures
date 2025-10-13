#include <stab.h>
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
