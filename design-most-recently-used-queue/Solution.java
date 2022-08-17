// https://leetcode.com/problems/design-most-recently-used-queue

class Node {
    int val;
    Node next;
    Node prev;
    Node(int val){
        this.val=val;
    }
}

class MRUQueue {    
    Node head, tail;
    int size;
    public MRUQueue(int n) {
        size=0;
        head=tail=null;
        head=new Node(1);
        tail=head;
        for(int i=2;i<=n;i++){
            Node node=new Node(i);
            tail.next=node;
            node.prev=tail;
            tail=node;
        }
    }
    
    public void print(Node head){
        Node n=head;
        while(n!=null){
            System.out.print(n.val+"  ");
            n=n.next;
        }
        System.out.println();
    }
    
    public int fetch(int k) {
        Node node=head;
        for(int i=0;i<k-1;i++)
            node=node.next;
        Node prev=node.prev;
        Node next=node.next;
        if(next==null){
            return node.val;
        }
        if(prev==null){
            head=head.next;
            next.prev=null;
            Node node2=new Node(node.val);
            tail.next=node2;
            node2.prev=tail;
            tail=node2;
            return node.val;
        }
        prev.next=next;
        next.prev=prev;
        Node node2=new Node(node.val);
        tail.next=node2;
        node2.prev=tail;
        tail=node2;
        
        
        return node.val;
    }
}

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue obj = new MRUQueue(n);
 * int param_1 = obj.fetch(k);
 */