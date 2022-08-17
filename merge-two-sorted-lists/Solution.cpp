// https://leetcode.com/problems/merge-two-sorted-lists

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
    
    void addNode(ListNode* &head, ListNode* &tail, ListNode* &l1){
        if(head==NULL){
            head=tail=l1;
        } else {
            tail->next=l1;
            tail=l1;
        }
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *tail=NULL;
        ListNode *head=NULL;
        while(l1!=NULL && l2!=NULL){
            if(l1->val < l2->val){
                addNode(head,tail, l1);
                l1=l1->next;
            } else {
                addNode(head, tail, l2);
                l2=l2->next;
            }
        }
        while(l1!=NULL){
            addNode(head,tail, l1);
            l1=l1->next;
        }
        while(l2!=NULL){
            addNode(head, tail, l2);
            l2=l2->next;
        }
        return head;
    }
};