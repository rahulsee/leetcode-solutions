// https://leetcode.com/problems/partition-list

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
    ListNode* partition(ListNode* head, int x) {
        ListNode *newHead=NULL;
        ListNode *newTail=NULL;
        ListNode *ln=head;
        while(ln!=NULL){
            if(ln->val < x){
                ListNode *nn=new ListNode(ln->val);
                if(newHead==NULL){
                    newHead=nn;
                    newTail=nn;
                }
                else {
                    newTail->next=nn;
                    newTail=nn;
                }
            }
            ln=ln->next;
        }
        ln=head;
        while(ln!=NULL){
            if(ln->val >= x){
                ListNode *nn=new ListNode(ln->val);
                if(newHead==NULL){
                    newHead=nn;
                    newTail=nn;
                }
                else {
                    newTail->next=nn;
                    newTail=nn;
                }
            }
             ln=ln->next;
        }
        return newHead;
    }
};