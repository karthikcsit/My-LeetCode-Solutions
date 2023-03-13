/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
  /*      ListNode* prev=NULL;
    if(head->next==NULL)
    {
        delete head;
        return prev;
    }*/
       ListNode* temp1=new ListNode();
        temp1->next=head;
        ListNode* first=temp1;
        for(int i=0;i<n;i++)
        { 
           // first=first->next;//
            if(first->next==NULL)
            {
                return first;
            }
             first=first->next;
        }
        ListNode* second=temp1;
        while(first->next!=NULL)
        {
            first=first->next;
            second=second->next;
        }
         ListNode* temp=second->next;
        second->next=second->next->next;
        delete temp;
        
        return temp1->next;
        
    }
};