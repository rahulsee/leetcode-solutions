// https://leetcode.com/problems/delete-node-in-a-linked-list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *prev=node;
        ListNode *n=node->next;
        while(n->next)
        {
            prev->val=n->val;
            prev=n;
            n=n->next;
        }
        prev->val=n->val;
        prev->next=NULL;
    }
};