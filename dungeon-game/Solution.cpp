// https://leetcode.com/problems/dungeon-game

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int dp[dungeon.size()][dungeon[0].size()];
        memset(dp,0,sizeof(dp));
        int m=dungeon.size();
        int n=dungeon[0].size();
        dp[m-1][n-1]=1-dungeon[m-1][n-1];
        if(dp[m-1][n-1] <=0)
            dp[m-1][n-1]=1;
        for(int i=n-2;i>=0;i--)
        {
            dp[m-1][i]=dp[m-1][i+1]-dungeon[m-1][i];
            if(dp[m-1][i] <= 0)
                dp[m-1][i]=1;
        }
        for(int i=m-2;i>=0;i--){
            dp[i][n-1]=dp[i+1][n-1]-dungeon[i][n-1];
            if(dp[i][n-1] <= 0)
                dp[i][n-1]=1;
        }
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                dp[i][j]=min(dp[i+1][j],dp[i][j+1])-dungeon[i][j];
                if(dp[i][j] <= 0){
                    dp[i][j]=1;
                }
            }
        }
        return dp[0][0];
    }
};