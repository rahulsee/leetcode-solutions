// https://leetcode.com/problems/intersection-of-two-linked-lists

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
    
    int length(ListNode *head){
        int cnt=0;
        ListNode *r=head;
        while(r!=NULL){
            cnt++;
            r=r->next;
        }
        return cnt;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int x=length(headA);
        int y=length(headB);
        if(x<y){
            swap(headA, headB);
            swap(x,y);
        }
        for(int i=0;i<(x-y);i++){
            headA=headA->next;
        }
        if(headA==headB){
            return headA;
        }
        while(headA!=NULL){
            if(headA->next==headB->next){
                return headA->next;
            }
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
    }
};