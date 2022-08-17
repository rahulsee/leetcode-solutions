// https://leetcode.com/problems/top-k-frequent-elements

class Solution {
    
    public class Node{
        int first;
        int second;
        Node(int first,int second){
            this.first=first;
            this.second=second;
        }
    }
    
    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer,Integer>map=new HashMap<Integer,Integer>();
        for(int i=0;i<nums.length;i++){
            if(map.get(nums[i])==null)
                map.put(nums[i],1);
            else
                map.put(nums[i],map.get(nums[i])+1);
        }
      
        PriorityQueue<Node>pq=new PriorityQueue<Node>(new Comparator<Node>(){
            public int compare(Node a,Node b){
                return b.second - a.second;
            }
        });
        for(Map.Entry<Integer,Integer>entry: map.entrySet()){
            pq.add(new Node(entry.getKey(),entry.getValue()));
        }
        int ans[]=new int[k];
        int cur=0;
        while(cur < k && !pq.isEmpty()){
            ans[cur++]=pq.poll().first;
        }
        return ans;
    }
}