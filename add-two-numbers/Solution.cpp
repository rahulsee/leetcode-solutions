// https://leetcode.com/problems/add-two-numbers

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        int sum=0;
        int carry=0;
        ListNode *ans=NULL;
        ListNode *r=NULL;
        while(l1 && l2){
            int num=l2->val+l1->val+carry;
            sum=num%10;
            carry=num/10;
            ListNode *tmp=new ListNode(sum);
            if(ans==NULL){
                ans=tmp;
                r=tmp;
            }
            else {
                r->next=tmp;
                r=tmp;
            }
            l2=l2->next;
            l1=l1->next;
        }
        ListNode *nn;
        if(l1==NULL)
            nn=l2;
        else
            nn=l1;
        while(nn){
            int num=nn->val+carry;
            sum=num%10;
            carry=num/10;
            ListNode *tmp=new ListNode(sum);
            if(ans==NULL){
                ans=tmp;
                r=tmp;
            }
            else {
                r->next=tmp;
                r=tmp;
            }
            nn=nn->next;
        }
        if(carry){
            ListNode *tmp=new ListNode(carry);
            if(ans==NULL){
                ans=tmp;
                r=tmp;
            }
            else {
                r->next=tmp;
                r=tmp;
            }
        }
        return ans;
    }
};