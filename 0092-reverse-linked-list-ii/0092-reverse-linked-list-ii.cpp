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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right){
            return head;
        }
        ListNode* LeftNode=head;
        ListNode* RightNode=head;
        ListNode* Leftprev=new ListNode(0);
        ListNode* itr=head;
        int curr=1;
        while(itr){
            if(curr==left-1){
                Leftprev=itr;
            }
            if(curr==left){
                LeftNode=itr;
            }
            if(curr==right){
                RightNode=itr;
            }
            curr++;
            itr=itr->next;
        }
        ListNode* RightNext=RightNode->next;
        ListNode* prev=LeftNode;
        ListNode* nxt=LeftNode->next;
        ListNode* node=new ListNode(0);
        while(nxt!=RightNode){
            if(nxt){
                node=nxt->next;
            }
            if(nxt){
                nxt->next=prev;
            }
            prev=nxt;
            nxt=node;
        }
        nxt->next=prev;
        LeftNode->next=RightNext;
        if(left!=1){
            Leftprev->next=RightNode;
        }
        else{
            return RightNode;
        }
        return head;
    }
};