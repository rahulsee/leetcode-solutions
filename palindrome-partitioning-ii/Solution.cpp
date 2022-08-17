// https://leetcode.com/problems/palindrome-partitioning-ii

class Solution {
public:
    int minCut(string s) {
        int m=s.length();
        bool pal[m][m];
        for(int i=0;i<m;i++){
            pal[i][i]=1;
            if((i+1)<m)
                pal[i][i+1]=(s[i]==s[i+1]);
        }
        for(int l=3;l<=m;l++){
            int i=0;
            int j=l-1;
            while(j<m){
                pal[i][j]=(s[i]==s[j]) && (pal[i+1][j-1]);
                i++;
                j++;
            }
        }
        int dp[m];
        memset(dp, 0, sizeof(dp));
        dp[0]=0;
        for(int j=1;j<m;j++){
            if(pal[0][j]){
                dp[j]=0;
                continue;
            }
            dp[j]=numeric_limits<int>::max();
            for(int i=j;i>=1;i--){
                if(pal[i][j]){
                    dp[j]=min(dp[j], dp[i-1]+1);
                }
            }
        }
        return dp[m-1];
    }
};