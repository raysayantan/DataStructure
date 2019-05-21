/*
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *forward = head;
        ListNode *backword = head;
        ListNode *prev = backword;
        
        int i = 0;
        while( i < n){
          forward = forward->next;
          i++;
        }
        
        while(forward != NULL){
            forward = forward->next;
            prev = backword;
            backword = backword->next;
        }
        
        if(backword){
            prev->next = backword->next;
            if (backword == head){
                if(head->next) {
                    head = head->next;
                    delete backword;
                } else {
                    delete backword;
                    return NULL;
                }
            }   
        }
        return head;
    }
};
