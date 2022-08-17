// https://leetcode.com/problems/lfu-cache




class LFUCache {
    
    TreeSet<Node>treeSet;
    HashMap<Integer,Node>hashMap;
    int capacity;
    int time;
    
    
    public LFUCache(int capacity) {
        this.capacity=capacity;
        this.time=0;
        treeSet=new TreeSet<Node>(
        new Comparator<Node>(){
            public int compare(Node a,Node b)
            {
                if(a.freq==b.freq)
                {
                    return b.time-a.time;
                }
                return a.freq-b.freq;
            }
        }
        );
        
        hashMap=new HashMap<Integer,Node>();
    }
    
    public int get(int key) {
        if(hashMap.get(key)==null)
            return -1;
        Node node=hashMap.get(key);
        Node newNode=new Node();
        newNode.freq=node.freq+1;
        newNode.time=time;
        newNode.key=key;
        newNode.value=node.value;
        treeSet.remove(node);
        treeSet.add(newNode);
        hashMap.put(key,newNode);
        time--;
        return hashMap.get(key).value;
    }
    
    public void put(int key, int value) {
        if(hashMap.get(key)!=null){
            Node node=hashMap.get(key);
            
            Node newNode=new Node();
            newNode.key=node.key;
            newNode.value=value;
            newNode.time=time;
            newNode.freq=node.freq+1;
            
            treeSet.remove(node);
            treeSet.add(newNode);
            hashMap.put(key,newNode);
        }
        
        else{
            if(hashMap.size()==capacity){
                if(treeSet.size()>0){
                    Node node=treeSet.pollFirst();
                    System.out.println("REMOVING "+node.value);
                    hashMap.remove(node.key);
                }
                else{
                    return;
                }
            }
                Node newNode=new Node();
                newNode.key=key;
                newNode.value=value;
                newNode.freq=1;
                newNode.time=time;
                treeSet.add(newNode);
                hashMap.put(key,newNode);
            
            
        }
        time--;
        
    }
    
    class Node{
        int freq;
        int key;
        int value;
        int time;
    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */