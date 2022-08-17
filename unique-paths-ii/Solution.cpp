// https://leetcode.com/problems/unique-paths-ii

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid){
        int r=grid.size();
        if(r==0)
            return 0;
        int c=grid[0].size();
        if(c==0)
            return 0;
        int dp[r][c];
        memset(dp, 0, sizeof(dp));
        dp[0][0]=1-grid[0][0];
        for(int i=1;i<c;i++){
            if(grid[0][i]==0){
                dp[0][i]=dp[0][i-1];
            }
            else
                dp[0][i]=0;
        }
        for(int i=1;i<r;i++){
            if(grid[i][0]==0){
                dp[i][0]=dp[i-1][0];
            }
            else {
                dp[i][0]=0;
            }
        }
        for(int i=1;i<r;i++){
            for(int j=1;j<c;j++){
                if(grid[i][j]==0){
                    dp[i][j]=dp[i][j-1]+dp[i-1][j];
                }
                else {
                    dp[i][j]=0;
                }
            }
        }
        return dp[r-1][c-1];
    }
};