/*
Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
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
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode *curr = head;
        ListNode *prev = NULL;
        
        if(!head) return NULL;
        
        while(curr){
            ListNode *next = curr->next;
                        
            if(curr->val == val){
                if(curr == head){
                    head = next;
                } else {
                    prev->next = next;
                }
                delete curr;
            } else {
                prev = curr;
            }
            curr = next;
        }
        return head;
    }
};
