// https://leetcode.com/problems/distinct-subsequences

class Solution {
public:
    
    int dp[1007][1007];
    
    int solve(string s, string t, int i, int j, int dp[1007][1007]){
        
        if(dp[i][j]!=-1)
            return dp[i][j];

        if(i==s.length() || j==t.length()){
            return j==t.length();
        }
                
        dp[i][j]=solve(s, t, i+1, j, dp);
        
        if(s[i]==t[j]){
            dp[i][j]+=solve(s, t, i+1, j+1, dp);
        }
        return dp[i][j];
    }
    
    int numDistinct(string s, string t) {
        for(int i=0;i<1007;i++){
            for(int j=0;j<1007;j++){
                dp[i][j]=-1;
            }
        }
        return solve(s, t, 0, 0, dp);
    }
};