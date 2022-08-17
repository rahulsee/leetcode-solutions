// https://leetcode.com/problems/perfect-squares

class Solution {
public:
    int numSquares(int n) {
        vector<int>sq;
        for(int i=0;(i*i)<=n;i++){
            sq.push_back(i*i);
        }
        int dp[sq.size()+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=n;i++)
            dp[0][i]=99999;
        dp[0][0]=0;
        for(int i=1;i<=sq.size();i++)
        {
            for(int j=1;j<=n;j++){
                dp[i][j]=dp[i-1][j];
                if(sq[i-1] <=j)
                    dp[i][j]=min(dp[i][j],dp[i][j-sq[i-1]]+1);
            }
        }
        return dp[sq.size()][n];
    }
};