// https://leetcode.com/problems/reverse-nodes-in-k-group

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        stack<ListNode*>s;
        ListNode *ans=NULL;
        ListNode *r=NULL;
        while(head!=NULL){
            s.push(head);
            if(s.size()==k){
                while(!s.empty()){
                    if(ans==NULL){
                        ans=new ListNode(s.top()->val);
                        r=ans;
                    }
                    else {
                        r->next=new ListNode(s.top()->val);
                        r=r->next;
                    }
                    s.pop();
                }
            }
            head=head->next;
        }
        ListNode *rem=NULL;
         while(!s.empty()){
                    if(rem==NULL){
                        rem=new ListNode(s.top()->val);
                    }
                    else {
                        ListNode *tmp=new ListNode(s.top()->val);
                        tmp->next=rem;
                        rem=tmp;
                    }
                    s.pop();
                }
        r->next=rem;
        return ans;
    }
};