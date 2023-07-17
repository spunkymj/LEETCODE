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
    ListNode* reverse(ListNode* curr,ListNode* prev){
        while(curr){
            ListNode* nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* prev1=reverse(l1,NULL);
        ListNode* prev2=reverse(l2,NULL);
        
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