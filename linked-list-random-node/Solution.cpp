// https://leetcode.com/problems/linked-list-random-node

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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode *myhead;
    int len;
    
    Solution(ListNode* head) {
        myhead=head;
        ListNode *node=head;
        len=0;
        while(node!=NULL){
            len++;
            node=node->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int num=rand()%len;
        ListNode *node=myhead;
        for(int i=0;i<num;i++)
            node=node->next;
        return node->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */