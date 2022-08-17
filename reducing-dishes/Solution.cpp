// https://leetcode.com/problems/reducing-dishes

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int mini=-(5e8+7);
        int n=satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        int dp[n+1][n+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                dp[i][j]=mini;
            }
        }
        for(int i=0;i<n;i++)
        {
            dp[i][1]=satisfaction[i];
        }
        int ans=0;
        for(int t=2;t<=n;t++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=t-2;j<i;j++)
                {
                    dp[i][t]=max(dp[i][t],dp[j][t-1]+satisfaction[i]*t);
                }
                ans=max(ans, dp[i][t]);
            }
        }
        return ans;
    }
};