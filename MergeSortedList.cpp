/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *start = NULL, *r = NULL;
        
        if(l1 != NULL & l2 == NULL) return l1;
        if(!l1 && l2) return l2;
        if(l1 == NULL && l2 == NULL) return NULL;
        
        start = (l1->val <= l2->val)? l1:l2;
        r = start;
        
        if(l1 == start) l1 =  l1->next;
        else l2 = l2->next;
        
        while(l1 && l2){  
            //cout<<"r: "<<r->val<<endl;
            ListNode *t = NULL;
            t = r->next;
            if(l1->val <= l2->val){
                r->next = l1;
                //l2 = t;
                l1 = l1->next;
            } else if(l1->val > l2->val){
                r->next = l2;
                //l1 = t;
                l2 = l2->next;
            }
            if(r->next)
                r = r->next;
        }
        
        if(l1 && !l2){
            r->next = l1;
        } else if(!l1 && l2){
            r->next = l2;
        }
        
        return start;
    }
};
