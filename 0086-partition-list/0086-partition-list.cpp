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
    ListNode* partition(ListNode* head, int x) {
        ListNode* curr=new ListNode();
        ListNode* ret=curr;
        ListNode* temp=head;
        while(temp){
            if(temp->val<x){
                curr->next=new ListNode(temp->val);
                curr=curr->next;
            }
            temp=temp->next;
        }
        temp=head;
        while(temp){
            if(temp->val>=x){
                curr->next=new ListNode(temp->val);
                curr=curr->next;
            }
            temp=temp->next;
        }
        return ret->next;
    }
};