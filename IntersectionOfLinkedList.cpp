/*
Write a program to find the node at which the intersection of two singly linked lists begins.
Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
Output: Reference of the node with value = 8
Input Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect). 
From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,0,1,8,4,5]. 
There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p = NULL, *q = NULL;
        ListNode *ret = NULL;
        if(headA == NULL || headB == NULL) ret == NULL;
        else {
            p = headA;
            int c1 = 0;
            while(p){
                p = p->next;
                c1++;
            }
            
            q = headB;
            int c2 = 0;
            while(q){
                q = q->next;
                c2++;
            }
            
            p = (c1 > c2)? headA : headB;
            q = headB;
            if(p == q){
                q = headA;
            }
            int d = abs(c1 - c2);
            
            for(int i = 0; i< d; i++){
                p = p->next;
            }
            
            while(p && q && p != q){
                p = p->next;
                q = q->next;
            }
            if( p == NULL || q == NULL) ret = NULL;
            else ret = p;
        }
        
        return ret;
    }
};
