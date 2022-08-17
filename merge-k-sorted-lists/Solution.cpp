// https://leetcode.com/problems/merge-k-sorted-lists

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
    
     ListNode *solve(ListNode *x, ListNode *y){
        ListNode *ans=NULL;
        ListNode *r=NULL;
        while(x && y){
            int v;
            if(x->val < y->val){
                v=x->val;
                x=x->next;
            }
            else {
                v=y->val;
                y=y->next;
            }
            if(ans==NULL){
                ans=new ListNode(v);
                r=ans;
            }
            else {
                r->next=new ListNode(v);
                r=r->next;
            }
        }
        while(x){
            int v;
            v=x->val;
            x=x->next;
            if(ans==NULL){
                ans=new ListNode(v);
                r=ans;
            }
            else {
                r->next=new ListNode(v);
                r=r->next;
            }
        }
        while(y){
            int v;
            v=y->val;
            y=y->next;
            if(ans==NULL){
                ans=new ListNode(v);
                r=ans;
            }
            else {
                r->next=new ListNode(v);
                r=r->next;
            }
        }
        return ans;
    }
    
     ListNode* merge(vector<ListNode*>& lists, int start, int end){
         if(lists.size()==0)
             return NULL;
        if(start==end){
            return lists[start];
        }
        int mid=start+(end-start)/2;
        ListNode *left=merge(lists, start, mid);
        ListNode *right=merge(lists, mid+1, end);
        ListNode *ans=solve(left, right);
        return ans;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size()-1);
    }
};