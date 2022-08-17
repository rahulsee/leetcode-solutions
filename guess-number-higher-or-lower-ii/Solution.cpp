// https://leetcode.com/problems/guess-number-higher-or-lower-ii

class Solution {
public:

    long long solve(int low, int high, int dp[][201]){
        if(dp[low][high]>0)
            return dp[low][high];
        long long ans=numeric_limits<int>::max();
        if(low>high){
            return 0;
        }
        if(high-low==1){
            dp[low][high]=low;
            return dp[low][high];
        }
        if(high==low){
            dp[low][high]=0;
            return dp[low][high];
        }
        for(int i=low;i<=high;i++){
            ans=min(ans, i+max(solve(i+1, high, dp), solve(low, i-1, dp)));
        }
        dp[low][high]=ans;
        return ans;
    }
    
    int getMoneyAmount(int n) {
        int dp[201][201];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                dp[i][j]=-1;
            }
        }
        return solve(1, n, dp);
    }
};