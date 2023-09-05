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
        //Interleaving new and old linked list  (old1->new1->old2->new2-> ......)
        Node* curr=head;
        while(curr!=NULL){
            Node* nxt=curr->next;
            curr->next=new Node(curr->val);
            curr->next->next=nxt;
            curr=curr->next->next;
        }
        
        //Attaching random pointers
        curr=head;
        while(curr!=NULL){
            if(curr->random){
                curr->next->random=curr->random->next;
            }
            curr=curr->next->next;
        }
        
        //Restoring old and new Linked List
        curr=head;
        Node* new_head=new Node(0);
        Node* cpy=new_head;
        while(curr!=NULL){
            cpy->next=curr->next;
            cpy=cpy->next;
            curr->next=curr->next->next;
            curr=curr->next;
        }
        return new_head->next;
    }
};