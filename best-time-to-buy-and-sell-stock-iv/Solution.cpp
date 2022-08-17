// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
         int n=prices.size();
        int dp[k+1][n+1];
        memset(dp, 0, sizeof(dp));
        if(prices.size()==0)
            return 0;
        int maxi=0;
        for(int i=1;i<=k;i++){
            int maxDiff=-prices[0];
            for(int j=1;j<=n;j++){
                dp[i][j]=max(dp[i][j-1], maxDiff+prices[j-1]);
                maxDiff=max(maxDiff, dp[i-1][j]-prices[j-1]);
                maxi=max(maxi, dp[i][j]);
            }
        }
        return maxi;
    }
};