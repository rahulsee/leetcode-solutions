// https://leetcode.com/problems/maximal-square

class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        rows=len(matrix)
        cols=len(matrix[0])
        dp=[[0]*cols for i in range(rows)]
        ans=0
        for i in range(rows):
            for j in range(cols):
                if i==0 or j==0:
                    dp[i][j]=int(matrix[i][j])
                    ans=max(ans, dp[i][j])
                else:
                    val=int(matrix[i][j])
                    if val == 1:
                        dp[i][j]=min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1
                    else:
                        dp[i][j]=0
                    ans=max(ans, dp[i][j])
        return ans*ans
            
                        
        