// https://leetcode.com/problems/minimum-falling-path-sum

class Solution {
    public int minFallingPathSum(int[][] A) {
        int r=A.length;
        int c=A[0].length;
        int dp[][]=new int[r][c];
        for(int i=0;i<c;i++)
            dp[0][i]=A[0][i];
        for(int i=1;i<r;i++){
            for(int j=0;j<c;j++){
                if(j==0){
                    dp[i][j]=Math.min(dp[i-1][j],dp[i-1][j+1])+A[i][j];
                }
                else if(j==c-1){
                 dp[i][j]=Math.min(dp[i-1][j],dp[i-1][j-1])+A[i][j];   
                }
                else{
                    dp[i][j]=Math.min(dp[i-1][j],Math.min(dp[i-1][j+1],dp[i-1][j-1]))+A[i][j];
                }
            }
        }
        int minans=Integer.MAX_VALUE;
        for(int i=0;i<c;i++){
            minans=Math.min(dp[r-1][i],minans);
        }
        return minans;
        
    }
}