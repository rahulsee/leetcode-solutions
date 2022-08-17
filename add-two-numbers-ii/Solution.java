// https://leetcode.com/problems/add-two-numbers-ii

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
    
    public int findLength(ListNode node){
        int len=0;
        while(node!=null){
            len++;
            node=node.next;
        }
        return len;
    }
    
    public ListNode addNode(ListNode l1, int p, int q){
        while(p < q){
             if(l1==null){
                 l1=new ListNode(0);
             }
             else {
                 ListNode head=new ListNode(0);
                 head.next=l1;
                 l1=head;
             }
            p++;
         }
        return l1;
    }
    
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
         int p=findLength(l1);
         int q=findLength(l2);
         l1=addNode(l1,p,q);
         l2=addNode(l2,q,p);
         Stack<ListNode>stack1=new Stack<>();
         ListNode tmp1=l1;
         while(tmp1!=null){
             stack1.push(tmp1);
              tmp1=tmp1.next;
         }
         Stack<ListNode>stack2=new Stack<>();
         ListNode tmp2=l2;
         while(tmp2!=null){
             stack2.push(tmp2);
              tmp2=tmp2.next;
         }
         ListNode ans=null;
         int sum=0;
         int carry=0;
         while(!stack2.isEmpty()){
             ListNode a=stack1.pop();
             ListNode b=stack2.pop();
             sum=a.val+b.val+carry;
             carry=sum/10;
             ListNode n=new ListNode(sum%10);
             n.next=ans;
             ans=n;
         }
        if(carry > 0){
            ListNode n=new ListNode(carry);
            n.next=ans;
            ans=n;
        }
        return ans;
    }
}