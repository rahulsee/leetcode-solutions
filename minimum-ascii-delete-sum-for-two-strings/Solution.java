// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings

class Solution {
    public int minimumDeleteSum(String s1, String s2) {
        int dp[][];
        int m=s1.length();
        int n=s2.length();
        dp=new int[m+1][n+1];
        
        dp[0][0]=0;
        for(int i=1;i<=m;i++){
            dp[i][0]=dp[i-1][0]+(int)s1.charAt(i-1);
            System.out.println("ROW "+dp[i][0]);
        }
        
        for(int i=1;i<=n;i++){
            dp[0][i]=dp[0][i-1]+(int)s2.charAt(i-1);
            System.out.println("COL "+dp[0][i]);
        }
    
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1.charAt(i-1)==s2.charAt(j-1)){
                    dp[i][j]=dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=Math.min(dp[i-1][j]+(int)s1.charAt(i-1),dp[i][j-1]+(int)s2.charAt(j-1));
                }
            }
        }
        return dp[m][n];
    }
}