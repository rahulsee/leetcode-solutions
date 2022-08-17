// https://leetcode.com/problems/palindrome-linked-list

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
    
    void solve(ListNode *&x, ListNode *head, bool &flag){
        if(head==NULL)
            return;
        solve(x, head->next, flag);
        if(head->val!=x->val)
            flag=false;
        x=x->next;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode *x=head;
        bool flag=true;
        solve(x, head, flag);
        return flag;
    }
};