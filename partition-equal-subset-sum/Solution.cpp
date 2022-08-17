// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.size()==1)
            return false;
        int sum=0;
        for(int n:nums)
            sum+=n;
        if(sum%2)
            return false;
        int target=sum/2;
        
        int dp[nums.size()+1][target+1];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=0;i<nums.size();i++)
            dp[i][0]=1;
        for(int i=1;i<=nums.size();i++){
            for(int j=1;j<=target;j++){
                dp[i][j]=dp[i-1][j];
                if(nums[i-1]<=j)
                    dp[i][j]=max(dp[i][j],dp[i-1][j-nums[i-1]]);
            }
        }
        return dp[nums.size()][target];
    }
};