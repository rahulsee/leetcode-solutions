// https://leetcode.com/problems/minimum-cost-tree-from-leaf-values

class Solution {
    public int mctFromLeafValues(int[] arr) {
         int m=arr.length;
         int dp[][]=new int[m][m];
         int max[][]=new int[m][m];
         for(int i=0;i<m;i++){
             dp[i][i]=0;
             max[i][i]=arr[i];
         }
         for(int i=0;i<m-1;i++){
             dp[i][i+1]=arr[i]*arr[i+1];
             max[i][i+1]=Math.max(arr[i],arr[i+1]);
         }
        
        for(int l=3;l<=m;l++){
            int i=0;
            int j=l-1;
            while(j<m){
                max[i][j]=Math.max(max[i][j-1],max[i+1][j]);
                i++;
                j++;
            }
        }
        
        for(int l=3;l<=m;l++){
            int i=0;
            int j=l-1;
            while(j<m){
                dp[i][j]=Integer.MAX_VALUE;
                for(int k=i;k<j;k++){
                    dp[i][j]=Math.min(dp[i][j],dp[i][k]+dp[k+1][j]+max[i][k]*max[k+1][j]);
                }
                i++;
                j++;
            }
        }
    
        
        return dp[0][m-1];
    }
}