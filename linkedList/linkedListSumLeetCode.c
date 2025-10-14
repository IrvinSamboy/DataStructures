#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* result = (ListNode*)malloc(sizeof(ListNode));

    result->val = 0;
    result->next = NULL;
    ListNode* currentList = result;
    char carry = 0;

    while (l1 != NULL || l2 != NULL)
    { 
        int value = (l1!=NULL? l1->val : 0) + (l2!=NULL? l2->val : 0) + carry;
        carry = 0;
        if(value > 9){
            carry = value/10;
            value = value%10;
        }
        
        currentList->val = value;
        
        if(l1 != NULL){
            l1 = l1->next;
        }
        if(l2 != NULL){
            l2 = l2->next;
        }

        if(l1 != NULL || l2 != NULL || carry != 0) {
            currentList->next = (ListNode*)malloc(sizeof(ListNode));
            (*currentList->next).val = carry;
            (*currentList->next).next = NULL;
            currentList = currentList->next;
        }
        else {
            currentList->next = NULL;
        }
    }
    return result;
}

