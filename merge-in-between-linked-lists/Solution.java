// https://leetcode.com/problems/merge-in-between-linked-lists

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
    
    public ListNode findTail(ListNode node){
        ListNode tmp=node;
        while(tmp.next!=null)
            tmp=tmp.next;
        return tmp;
    }
    
    public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        ListNode prev1=null;
        ListNode node=list1;
        while(node.val != a)
        {
            prev1=node;
            node=node.next;
        }
        // System.out.println(node.val);
        ListNode prev2=null;
        node=list1;
        while(node.val != b){
            prev2=node;
            node=node.next;
        }
        // System.out.println(node.val);
        ListNode tail=findTail(list2);
        if(prev1!=null && prev2!=null){
            prev1.next=list2;
            if(node==null)
                tail.next=null;
            else
                tail.next=node.next;
            return list1;
        }
        else {
            if(node==null)
                tail.next=null;
            else
                tail.next=node.next;
            return list2;
        }
        
    }
}