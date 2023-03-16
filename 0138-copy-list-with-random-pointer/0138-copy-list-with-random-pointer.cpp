/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        for( Node* curr=head;curr!=NULL;)
        {
             Node* nxt=curr->next;
            curr->next=new  Node(curr->val);
            curr->next->next=nxt;
            curr=nxt;
        }
         for( Node* curr=head;curr!=NULL;curr=curr->next->next)
             curr->next->random=(curr->random!=NULL)?curr->random->next:NULL;
        
      Node*  curr=head;
       Node* pseudoh=new Node(0);
        Node* copy=pseudoh;
        while(curr!=NULL)
        {
            Node* nxt=curr->next->next;
             copy->next=curr->next;
            curr->next=nxt;
            copy=copy->next;
            curr=curr->next;
        }
        return pseudoh->next;
        
    }
};