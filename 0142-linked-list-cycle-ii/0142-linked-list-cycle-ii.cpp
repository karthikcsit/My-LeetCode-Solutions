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
    ListNode *detectCycle(ListNode *head) {
         ListNode *slow=head;
         ListNode *fast=head;
      //  ListNode *pos=new ListNode(-1);//
       if(head==NULL || head->next==NULL) return NULL;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast) break;
        }
        if(slow!=fast) return NULL;
        slow=head;
        while(slow->next!= fast->next)
        {
            slow=slow->next;
            fast=fast->next;
        }
       if( fast->next->next==slow)  return slow;
      else
        return fast->next;
        
    }
};