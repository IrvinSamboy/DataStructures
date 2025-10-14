#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

ListNode* createNode(int data){
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    
    if(!newNode){
        printf("Error: An error occurred while allocating memory space.");
    }

    newNode->val = data;
    newNode->next = NULL;

    return newNode;
}

ListNode* reverseList(ListNode* list) {
    ListNode* listReversed = NULL;
    ListNode* prevList = NULL;
    ListNode* prevListReversed = listReversed;
    while (list != NULL)
    {
        if(prevList != NULL){
            if(listReversed == NULL){
                listReversed = createNode(prevList->val);
                listReversed->next = NULL;
            }
            else{
                prevListReversed=listReversed;
                listReversed = createNode(prevList->val);
                listReversed->next=prevListReversed;
            }
        }

        prevList = list;
        
        if(list->next == NULL) {
            prevListReversed=listReversed;
            listReversed = createNode(list->val);
            listReversed->next=prevListReversed;
        }

        list = list->next;        

    }
    
    return listReversed;
}
