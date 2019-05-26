/*
Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *next = NULL;
        ListNode *start = head;
        ListNode *s1 = NULL;
        ListNode *s2 = NULL;

        if(head == NULL) return NULL;
        if(curr->next == NULL) return head;
        if(n == m) return head;
        
        for(int i = 1; i < m; i++){
            prev = curr;
            curr = curr->next;
        }
        //cout<<"curr 1:"<<curr->val<<endl;
        if(curr) s1 = curr;
        s2 = prev;
        
        for(int i = 0; i<= n-m; i++){
            cout<<"curr 2:"<<curr->val<<endl;
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        //cout<<prev->val<<":"<<curr->val<<":"<<next->val<<endl;
        if(s1) s1->next = curr;
        if(s2) s2->next = prev;
        if(m == 1){
            start = prev;
            return start;
        }
        
        return start;
    }
};
