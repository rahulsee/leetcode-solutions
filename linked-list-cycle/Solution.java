// https://leetcode.com/problems/linked-list-cycle

/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        HashSet<ListNode>visited=new HashSet<>();
        while(head!=null){
            visited.add(head);
            if(head.next!=null && visited.contains(head.next)){
                return true;
            }
            head=head.next;
        }
        return false;
    }
}