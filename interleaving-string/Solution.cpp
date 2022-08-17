// https://leetcode.com/problems/interleaving-string

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m=s1.length();
        int n=s2.length();
        int dp[m+1][n+1];
        if((s1.length()+s2.length())!=s3.length())
            return false;
        if(s2.length()==0)
            return s1==s3;
        if(s1.length()==0)
            return s2==s3;
        memset(dp, 0, sizeof(dp));
        dp[0][0]=1;
        bool ssa[s1.length()];
        memset(ssa, 0, sizeof(ssa));
        int cura=0;
        bool ssb[s2.length()];
        memset(ssb, 0, sizeof(ssb));
        int curb=0;
        int curc=0;
        while(cura<s1.length() && curc<s3.length()){
            if(s1[cura]==s3[curc]){
                ssa[cura]=true;
                cura++;
                curc++;
            }
            else {
                curc++;
            }
        }
        curc=0;
        while(curb<s2.length() && curc<s3.length()){
            if(s1[curb]==s3[curc]){
                ssb[curb]=true;
                curb++;
                curc++;
            }
            else {
                curc++;
            }
        }
        for(int i=1;i<=m;i++){
            cout<<ssa[i-1]<<endl;
            dp[i][0]=ssa[i-1];
        }
        for(int i=1;i<=n;i++){
            dp[0][i]=ssb[i-1];
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s3[i+j-1]==s1[i-1]){
                    dp[i][j]=dp[i][j] || (dp[i-1][j]);
                }
                if(s3[i+j-1]==s2[j-1]){
                    dp[i][j]=dp[i][j] || (dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};