// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold

class Solution {
    
    public int findSum(int []nums, int div){
        int sum=0;
        for(int i=0;i<nums.length;i++){
            sum=sum+(int)Math.ceil((double)nums[i]/(double)div);
        }
        return sum;
    }
    
    public int findMax(int []nums){
        int max=Integer.MIN_VALUE;
        for(int i=0;i<nums.length;i++){
            max=Math.max(nums[i],max);
        }
        return max;
    }
    
    public int smallestDivisor(int[] nums, int threshold) {
        int low=1;
        int high=findMax(nums);
        int ans=Integer.MAX_VALUE;
        while(low<=high){
            int mid=low+(high-low)/2;
            int sum=findSum(nums, mid);
            if(sum > threshold){
                low=mid+1;
            }
            else {
                ans=Math.min(mid,ans);
                high=mid-1;
            }
        }
        return ans;
    }
}