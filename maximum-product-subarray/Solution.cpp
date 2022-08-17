// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int>dp(nums.size());
        vector<int>dp2(nums.size());
        dp[0]=dp2[0]=nums[0];
        int prod=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            prod*=nums[i];
            dp[i]=max(dp2[i-1]*nums[i],max(nums[i],max(dp[i-1]*nums[i], prod)));
            dp2[i]=min(dp2[i-1]*nums[i],min(nums[i],min(dp[i-1]*nums[i], prod)));
            ans=max(ans, dp[i]);
        }
        return ans;
    }
};