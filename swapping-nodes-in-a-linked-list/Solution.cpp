// https://leetcode.com/problems/swapping-nodes-in-a-linked-list

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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *k1=head, *k2=head;
        ListNode *r=head;
        for(int i=1;i<k;i++){
            r=r->next;
        }
        k1=r;
        r=r->next;
        while(r!=NULL){
            r=r->next;
            k2=k2->next;
        }
        swap(k1->val, k2->val);
        return head;
    }
};