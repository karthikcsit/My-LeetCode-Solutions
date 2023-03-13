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
    ListNode* reverseKGroup(ListNode* head, int k) {
  ListNode* temp=head;
        int length=0;

        //find length of the list
        while(temp!=NULL){
            temp=temp->next;
            length++;
        }

        bool isFirstGrp=1;                    
        ListNode* curr=head;
        ListNode* firstOfPrev=NULL;
        for(int i=0;i<length/k;i++){
            ListNode* prev=NULL;
            ListNode* first=curr;
            int cnt=0;
            //reversing the list with 'k' nodes
            while(curr!=NULL && cnt<k){
                ListNode* next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
                cnt++;
            }
            //If its first group 'head' will be 'prev'
            if(isFirstGrp){
                head=prev;
                isFirstGrp=0;
            }
            else{
                //attaching the reversed list with the remaining list
                firstOfPrev->next=prev;
            }
            firstOfPrev=first;
            //if its the last group with 'k' nodes connecting
            //it with the remaining nodes less than 'k'
            firstOfPrev->next=curr;
        }
        return head;
    }
};