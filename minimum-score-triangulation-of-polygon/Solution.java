// https://leetcode.com/problems/minimum-score-triangulation-of-polygon

class Solution {  
    public int minScoreTriangulation(int[] A) {
        int dp[][];
        int rows=A.length;
        dp=new int[rows][rows];
        for(int i=0;i<rows;i++){
            for(int j=0;j<rows;j++)
                dp[i][j]=Integer.MAX_VALUE;
        }
        for(int i=0;i<rows;i++)
            dp[i][i]=0;
        for(int i=0;i<rows-1;i++)
            dp[i][i+1]=0;
        for(int i=0;i<rows-2;i++)
            dp[i][i+2]=A[i]*A[i+1]*A[i+2];
        for(int l=4;l<=rows;l++){
            int i=0;
            int j=l-1;
            while(j<rows){
                for(int k=i+1;k<j;k++){
                    dp[i][j]=Math.min(dp[i][j],dp[i][k]+dp[k][j]+A[i]*A[j]*A[k]);
                }
                i++;
                j++;
            }
        }
        
        return dp[0][rows-1];
    }
}