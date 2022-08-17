// https://leetcode.com/problems/delete-and-earn

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxi=0;
        unordered_map<int,int>count;
        for(int n:nums){
            count[n]++;
            maxi=max(n, maxi);
        }
        int dp[maxi+1];
        memset(dp,0, sizeof(dp));
        dp[1]=count[1];
        int ans=dp[1];
        for(int i=2;i<=maxi;i++){
            dp[i]=max(i*count[i]+dp[i-2], dp[i-1]);
            ans=max(ans, dp[i]);
        }
        return ans;
    }
};