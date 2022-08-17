// https://leetcode.com/problems/remove-nth-node-from-end-of-list

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast=head;
        ListNode *slow=head;
        ListNode *prev=NULL;
        int cnt=0;
        while(fast!=NULL){
            fast=fast->next;
            cnt++;
            if(cnt > n){
                prev=slow;
                slow=slow->next;
            }
        }
        ListNode *next=slow->next;
        if(prev==NULL){
            head=head->next;
        }
        else {
            prev->next=next;
        }
        return head;
    }
};