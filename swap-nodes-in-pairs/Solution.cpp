// https://leetcode.com/problems/swap-nodes-in-pairs

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
    ListNode* swapPairs(ListNode* head) {
        ListNode *ans=NULL;
        ListNode *r=NULL;
        ListNode *a=NULL;
        ListNode *b=NULL;
        while(head!=NULL){
            a=head;
            b=head->next;
            if(head->next){
                head=head->next->next;
            }
            else {
                head=head->next;
            }
            if(a && b){
                a->next=NULL;
                b->next=NULL;
                if(ans==NULL){
                    ans=b;
                    r=b;
                    r->next=a;
                    r=a;
                }
                else {
                    r->next=b;
                    r->next->next=a;
                    r=a;
                }
            }
            else if(a){
                a->next=NULL;
                if(ans==NULL){
                    ans=a;
                    r=a;
                }
                else {
                    r->next=a;
                    r=a;
                }
            }
        }
        return ans;
    }
};