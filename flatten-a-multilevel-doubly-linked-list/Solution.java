// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list

/*
// Definition for a Node.
class Node {
    public int val;
    public Node prev;
    public Node next;
    public Node child;
};
*/

class Solution {
    Node ansHead;
    HashSet<Node>visited;
    Node ans;
    void addNode(Node node){
        //System.out.println(node.val);
        if(ansHead==null)
        {
            ansHead=new Node();
            ansHead.val=node.val;
            ansHead.next=null;
            ansHead.prev=null;
            ans=ansHead;
        }
        else
        {
            Node nextNode=new Node();
            nextNode.val=node.val;
            nextNode.next=null;
            ansHead.next=nextNode;
            nextNode.prev=ansHead;
            ansHead=nextNode;
        }
    }
    
    void DFS(Node head){
        if(head==null || visited.contains(head))
            return ;
        visited.add(head);
        addNode(head);
        DFS(head.child);
        DFS(head.next);
    }
    
    public Node flatten(Node head) {
        if(head==null)
            return null;
        ansHead=null;
        visited=new HashSet<Node>();
        DFS(head);
        //System.out.println("Values are");
        // while(ansHead!=null)
        // {
        //     System.out.print(ansHead.val+" ");
        //     ansHead=ansHead.next;
        // }
        return ans;
    }
}