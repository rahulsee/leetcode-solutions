// https://leetcode.com/problems/subsets

class Solution {
    
    List<List<Integer> >list;
    boolean []flag;
    public void solve(int []nums,int cur,boolean []flag){
        
        if(cur==nums.length){
            ArrayList<Integer>arr=new ArrayList<>();
            for(int i=0;i<nums.length;i++)
            {
                if(flag[i]==true){
                    arr.add(nums[i]);
                }
            }
            list.add(arr);
            return;
        }
        
        flag[cur]=true;
        solve(nums,cur+1,flag);
        flag[cur]=false;
        solve(nums,cur+1,flag);
    }
    
    public List<List<Integer>> subsets(int[] nums) {
        list=new ArrayList<List<Integer> >();
        flag=new boolean[nums.length];
        solve(nums,0,flag);
        return list;
    }
}