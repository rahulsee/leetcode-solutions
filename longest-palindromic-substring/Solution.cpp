// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        bool dp[n][n];
        int maxlen=1;
        int start=0;
        for(int i=0;i<n;i++)
            dp[i][i]=1;
        for(int i=0;i<(n-1);i++){
            dp[i][i+1]=(s[i]==(s[i+1]));
            if(dp[i][i+1]){
                start=i;
                maxlen=2;
            }
        }
        for(int l=3;l<=n;l++){
            int i=0;
            int j=l-1;
            while(j<n){
                if((s[i]==s[j]) && dp[i+1][j-1]==1){
                    dp[i][j]=1;
                }
                else {
                    dp[i][j]=0;
                }
                if(dp[i][j]==1){
                    if(maxlen < (j-i+1)){
                        start=i;
                        maxlen=j-i+1;
                    };
                }
                i++;
                j++;
            }
        }
        return s.substr(start, maxlen);
    }
};