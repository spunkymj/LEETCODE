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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr1=l1;
        ListNode* prev1=NULL;
        while(curr1){
            ListNode* nxt=curr1->next;
            curr1->next=prev1;
            prev1=curr1;
            curr1=nxt;
        }
        ListNode* curr2=l2;
        ListNode* prev2=NULL;
        while(curr2){
            ListNode* nxt=curr2->next;
            curr2->next=prev2;
            prev2=curr2;
            curr2=nxt;
        }
        int carry=0;
        ListNode* curr=new ListNode();
        ListNode* prev=NULL;
        while(prev1 && prev2){
            curr->val=(prev1->val+prev2->val+carry)%10;
            carry=(prev1->val+prev2->val+carry)/10;
            curr->next=prev;
            prev=curr;
            curr=new ListNode();
            prev1=prev1->next;
            prev2=prev2->next;
        }
        while(prev1){
            curr->val=(prev1->val+carry)%10;
            carry=(prev1->val+carry)/10;
            curr->next=prev;
            prev=curr;
            curr=new ListNode();
            prev1=prev1->next;
        }
        while(prev2){
            curr->val=(prev2->val+carry)%10;
            carry=(prev2->val+carry)/10;
            curr->next=prev;
            prev=curr;
            curr=new ListNode();
            prev2=prev2->next;
        }
        if(carry){
            curr->val=carry;
            curr->next=prev;
            prev=curr;
        }
        return prev;
    }
};