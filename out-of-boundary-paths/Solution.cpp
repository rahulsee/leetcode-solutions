// https://leetcode.com/problems/out-of-boundary-paths

class Solution {
public:
    
    
    int m,n;
    int maxMove;
    long long dp[57][57][57];
    
    bool outOfRange(int curX, int curY)
    {
        return curX>=m || curX<0 || curY>=n || curY<0;
    }
    
    long long solve(int startRow, int startColumn, int maxMove)
    {    
        if(outOfRange(startRow, startColumn) && maxMove>=0)
            return 1;
        if(maxMove==0)
            return 0;
        
        if(dp[startRow][startColumn][maxMove]!=-1)
            return dp[startRow][startColumn][maxMove];
        
        long long a=solve(startRow-1, startColumn, maxMove-1)%1000000007;
        long long b=solve(startRow+1, startColumn, maxMove-1)%1000000007;
        long long c=solve(startRow, startColumn-1, maxMove-1)%1000000007;
        long long d=solve(startRow, startColumn+1, maxMove-1)%1000000007;
        dp[startRow][startColumn][maxMove]=a+b+c+d;
        return dp[startRow][startColumn][maxMove];
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        this->maxMove=maxMove;
        this->m=m;
        this->n=n;
        int ans=0;
        for(int i=0;i<57;i++)
        {
            for(int j=0;j<57;j++)
            {
                for(int k=0;k<57;k++)
                {
                    dp[i][j][k]=-1;
                }
            }
        }
        solve(startRow, startColumn, maxMove);
        int res=dp[startRow][startColumn][maxMove]%1000000007;
        return max(res, 0);
    }
};