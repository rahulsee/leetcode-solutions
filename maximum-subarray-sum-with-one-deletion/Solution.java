// https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion

class Solution {

    public int maximumSum(int[] arr) {
        int n=arr.length;
        int count=0;
        int maxneg=Integer.MIN_VALUE;
        for(int i=0;i<n;i++){
            if(arr[i] < 0)
                count++;
            maxneg=Math.max(maxneg,arr[i]);
        }
        if(count==n)
            return maxneg;
        
         int leftSum[]=new int[n];
         int rightSum[]=new int[n];
         
        int max_sf=0;
        int max_ov=Integer.MIN_VALUE;
        for(int i=0;i<n;i++)
        {
            max_sf=Math.max(arr[i],max_sf+arr[i]);
            leftSum[i]=max_sf;
            max_ov=Math.max(max_sf,max_ov);
        }
        
        max_sf=0;
        for(int i=n-1;i>=0;i--){
            max_sf=Math.max(arr[i],max_sf+arr[i]);
            rightSum[i]=max_sf;
        }
         
        int ans=max_ov;
        
        for(int i=1;i<n-1;i++){
            ans=Math.max(ans,leftSum[i-1]+rightSum[i+1]);
        }
        return ans;
    }
}