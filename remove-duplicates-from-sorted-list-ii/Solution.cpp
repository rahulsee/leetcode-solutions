// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *newHead;
        newHead=NULL;
        ListNode *r=NULL;
        while(head!=NULL){
            int cnt=0;
            while(head->next && (head->val == head->next->val)){
                head=head->next;
                cnt++;
            }
            if(!cnt){
                ListNode *n=new ListNode(head->val);
                n->next=NULL;
                if(newHead==NULL){
                    newHead=n;
                    r=n;
                }
                else {
                    r->next=n;
                    r=n;
                }
            }
            head=head->next;
        }
        return newHead;
    }
};