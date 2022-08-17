// https://leetcode.com/problems/insertion-sort-list

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    
    ListNode newHead;
    
    public void insert(ListNode node){
        if(newHead==null) {
            newHead=node;
            return;
        }
        ListNode r=newHead;
        ListNode prev=null;
        while(r!=null && r.val < node.val){
            prev=r;
            r=r.next;
        }
        if(prev!=null) {
            prev.next=node;
            node.next=r;
        }
        else{
            newHead=node;
            node.next=r;
        }
        
    }
    
    public ListNode insertionSortList(ListNode head) {
        newHead=null;
        while(head!=null){
            insert(new ListNode(head.val));
            head=head.next;
        }
        return newHead;
    }
}