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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* curr=list1;
        ListNode* end=list1;
        a--;
        while(a--){
            curr=curr->next;
        }
        while(b--){
            end=end->next;
        }
        end=end->next;
        curr->next=list2;
        ListNode* lst2=list2;
        while(lst2->next){
            lst2=lst2->next;
        }
        lst2->next=end;
        return list1;
    }
};