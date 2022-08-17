// https://leetcode.com/problems/allocate-mailboxes

class Solution {
public:
    
    int dp[107][107];
    int cost[107][107];

    
    int solve(vector<int>&houses, int start, int k)
    {
        int n=houses.size();
        if(start==n && k==0)
        {
            return 0;
        }
        if(k==0)
        {
            return 1e9+7;
        }
        if(dp[start][k]!=-1)
            return dp[start][k];
        int ans=1e9+7;
        for(int i=start;i<n;i++)
        {
            ans=min(ans, solve(houses, i+1, k-1)+cost[start][i]);
        }
        dp[start][k]=ans;
        return dp[start][k];
    }
    
    int minDistance(vector<int>& houses, int k) {
         sort(houses.begin(), houses.end());
         int n=houses.size();
         memset(dp, -1, sizeof(dp));
         memset(cost, 0, sizeof(cost));
         for(int i=0;i<n;i++)
         {
             for(int j=i;j<n;j++)
             {
                 for(int k=i;k<=j;k++)
                 {
                     // We place the postbox at the median,
                     // if there is only one postbox to be placed.
                     cost[i][j]+=abs(houses[k]-houses[i+(j-i)/2]);
                 }
             }
         }
         return solve(houses, 0, k);
    }
};