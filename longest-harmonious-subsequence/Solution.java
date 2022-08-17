// https://leetcode.com/problems/longest-harmonious-subsequence

class Solution {
    public int findLHS(int[] nums) {
        HashMap<Integer, Integer>count=new HashMap<>();
        for(int i=0;i<nums.length;i++){
            if(count.containsKey(nums[i])){
                count.put(nums[i], count.get(nums[i])+1);
            }
            else {
                count.put(nums[i],1);
            }
        }
        int maxi=0;
        for(Integer key: count.keySet()){
            int a=(count.containsKey(key+1))?count.get(key+1):0;
            int b=count.get(key);
            if(a>0)
                maxi=Math.max(maxi, a+b);
        }
        return maxi;
    }
}