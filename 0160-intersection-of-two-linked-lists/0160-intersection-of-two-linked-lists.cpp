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
         int d=0,c1=0,c2=0;
        ListNode *curr=headA;
        ListNode *curr1=headB;
        while(curr!=NULL)
        {
            c1++;
            curr=curr->next;
        }
         while(curr1!=NULL)
        {
            c2++;
              curr1=curr1->next;
        }
        d=abs(c1-c2);
        curr=headA;
        curr1=headB;
        if(c1>c2)
        {
            
            for(int i=0;i<d;i++)
                curr=curr->next;
        }
        else
        {
            
             for(int j=0;j<d;j++)
                curr1=curr1->next;
            
        }
        while(curr!=NULL && curr1!=NULL)
        {
            if(curr==curr1)
                return curr;
            
            curr=curr->next;
             curr1=curr1->next;
        }
        return NULL;
    }
};