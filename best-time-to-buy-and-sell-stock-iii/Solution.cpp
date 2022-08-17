// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int dp[3][n+1];
        memset(dp, 0, sizeof(dp));
        int maxi=0;
        for(int i=1;i<=2;i++){
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