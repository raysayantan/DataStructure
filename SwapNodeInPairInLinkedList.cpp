/*
Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.

 

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
*/
ListNode *first = NULL;
        ListNode *second = NULL;
        ListNode *start = NULL;
        ListNode *temp = NULL;
        ListNode *temp1 = NULL;
        
        if(head == NULL) return NULL;
        if(head->next == NULL) return head;
        
        first = head;
        if(first->next) second = first->next;
        
        while(second && first){
            cout<<first->val<<":"<<second->val<<endl;
            temp = second->next;
            second->next = first;
            first->next = temp;
            
            if(NULL == start){
                start = second;
                temp1 = start->next;
            } else {
                temp1->next = second;
                temp1 = second->next;
            }
            if(first->next)cout<<"first next:"<<first->next->val<<endl;
            if(first)cout<<"first:"<<first->val<<endl;
            if(second->next)cout<<"second next:"<<second->next->val<<endl;
            if(second)cout<<"second :"<<second->val<<endl;
            if(temp1)cout<<"temp1:"<<temp1->val<<endl;
            if(temp1->next)cout<<"temp1 next:"<<temp1->next->val<<endl;
            if(temp){
                cout<<"temp:"<<temp->val<<endl;
                if(temp->next)cout<<"temp next:"<<temp->next->val<<endl;
            }
            first = temp;
            if(!first) break;
            second = first->next;
            cout<<"Start:"<<start->val<<endl;
            cout<<"Start->next:"<<start->next->val<<endl;
            cout<<"Start->next->next:"<<start->next->next->val<<endl;
            cout<<"Start->next->next->next:"<<start->next->next->next->val<<endl;
        }
        cout<<"Out of Loop"<<endl;
        
        //if(start->next->next->next->next) cout<<start->next->next->next->next->val<<endl;
        //else cout<<"end"<<endl;
        return start;
