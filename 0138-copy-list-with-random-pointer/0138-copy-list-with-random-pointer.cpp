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
        unordered_map<Node*,int> mp1;
        unordered_map<int,Node*> mp2;
        Node* curr=head;
        int id=1;
        while(curr!=NULL){
            mp2[id]=new Node(curr->val);
            mp1[curr]=id;
            id++;
            curr=curr->next;
        }
        curr=head;
        id=1;
        while(curr!=NULL){
            mp2[id]->next=mp2[mp1[curr->next]];
            if(curr->random){
                mp2[id]->random=mp2[mp1[curr->random]];
            }
            else{
                mp2[id]->random=NULL;
            }
            id++;
            curr=curr->next;
        }
        return mp2[1];
    }
};