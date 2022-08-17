// https://leetcode.com/problems/maximum-profit-in-job-scheduling

class Node{
    int start;
    int end;
    int profit;
    int maxprof;
    Node(int start,int end,int profit){
        this.start=start;
        this.end=end;
        this.profit=profit;
        this.maxprof=profit;
    }
    Node(){
        
    }
    public String toString(){
        return start+" "+end;
    }
}


class CustomComparator implements Comparator<Node>{
    public int compare(Node a, Node b){
        if(a.end==b.end)
        {
            return a.start-b.start;
        }
        return a.end-b.end;
    }
}

class Solution {
    
    public boolean combineOk(Node a,Node b){
        if(a.end <= b.start){
            return true;
        }
        return false;
    }
    
    public int upperBound(Node[] arr,int start,int end,int key)
    {
        int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(arr[mid].end > key){
                end=mid-1;
            }
            else{
                ans=Math.max(ans,mid);
                start=mid+1;
            }
        }
        return ans;
    }    
    
    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        
        Node arr[]=new Node[startTime.length];
        for(int i=0;i<startTime.length;i++){
            arr[i]=new Node(startTime[i],endTime[i],profit[i]);
        }
        
        int ans=arr[0].maxprof;
        Arrays.sort(arr,new CustomComparator());
        
        for(int i=1;i<arr.length;i++){
            int index=upperBound(arr,0,i-1,arr[i].start);
            if(index >=0)
            { 
              arr[i].maxprof=Math.max(arr[i].maxprof,arr[index].maxprof+arr[i].profit);
            }
            arr[i].maxprof=Math.max(arr[i].maxprof,arr[i-1].maxprof);
            System.out.println(arr[i]+" "+arr[i].maxprof);
            ans=Math.max(arr[i].maxprof,ans);
            System.out.println("INDEX IS "+index);
            
        }
        return ans;
    }
}