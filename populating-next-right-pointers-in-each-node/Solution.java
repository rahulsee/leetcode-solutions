// https://leetcode.com/problems/populating-next-right-pointers-in-each-node

/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class Solution {
    public Node connect(Node root) {
        if(root==null){
            return root;
        }
        Queue<Node>queue=new LinkedList<>();
        queue.add(root);
        while(true){
            ArrayList<Node>nodes=new ArrayList<>();
            if(queue.isEmpty())
                break;
            while(!queue.isEmpty()){
                nodes.add(queue.remove());
            }
            Node prev=null;
            for(Node n: nodes){
                if(prev!=null)
                    prev.next=n;
                if(n.left!=null)
                    queue.add(n.left);
                if(n.right!=null)
                    queue.add(n.right);
                prev=n;
            }   
        }
        return root;
    }
}