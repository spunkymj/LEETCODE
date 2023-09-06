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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n=0;
        ListNode* curr=head;
        while(curr){
            n++;
            curr=curr->next;
        }
        int sz=(n/k);
        vector<ListNode*> ans;
        curr=head;
        if(sz==0){
            while(curr){
                ListNode* nxt=curr->next;
                curr->next=NULL;
                ans.push_back(curr);
                curr=nxt;
            }
            int end=k-ans.size();
            for(int i=0 ; i<end ; i++){
                ans.push_back(NULL);
            }
        }
        else{
            int rem=n%k;
            for(int i=0 ; i<k ; i++){
                ListNode* start=curr;
                ListNode* prev=curr;
                for(int i=0 ; i<sz ; i++){
                    prev=curr;
                    curr=curr->next;
                    if(!curr){
                        break;
                    }
                }
                if(rem){
                    rem--;
                    prev=curr;
                    curr=curr->next;
                }
                prev->next=NULL;
                ans.push_back(start);
            }
        }
        return ans;
    }
};