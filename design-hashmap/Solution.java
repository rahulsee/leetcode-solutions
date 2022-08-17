// https://leetcode.com/problems/design-hashmap

class MyHashMap {
    class Node {
        int key;
        int value;
        Node next;
        Node prev;
        Node(int k, int v){
            key=k;
            value=v;
            next=null;
        }
    }
    /** Initialize your data structure here. */    
    Node []ht;
    
    public MyHashMap() {
        ht=new Node[1000007];
    }
    
    /** value will always be non-negative. */
    public void put(int key, int value) {
        int index=key%(1000007);
        if(ht[index]==null){
            ht[index]=new Node(key, value);
        }
        else {
            Node r=ht[index];
            while(r!=null){
                if(r.key==key) {
                    r.value=value;
                    return;
                }
                r=r.next;
            }
            Node nn=new Node(key, value);
            nn.next=ht[index];
            ht[index].prev=nn;
            ht[index]=nn;
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    public int get(int key) {
        int index=key%(1000007);
        if(ht[index]==null)
            return -1;
        Node r=ht[index];
        while(r!=null){
            if(r.key==key)
                return r.value;
            r=r.next;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    public void remove(int key) {
        int index=key%(1000007);
        if(ht[index]==null)
            return;
        Node r=ht[index];
        while(r!=null){
            if(r.key==key)
                break;
            r=r.next;
        }
        if(r==null)
            return;
        Node prev=r.prev;
        Node next=r.next;
        if(prev==null){
            ht[index]=ht[index].next;
        }
        else if(next==null){
            ht[index]=ht[index].prev;
        }
        else {
            prev.next=next;
            next.prev=prev;
        }
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */