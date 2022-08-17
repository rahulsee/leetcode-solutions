// https://leetcode.com/problems/number-of-distinct-roll-sequences

class Solution {
public:
    int distinctSequences(int n) {
        int dp[n+1][7][7];
        memset(dp, 0, sizeof(dp));
        int MOD=1e9+7;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=6;j++)
            {
                for(int k=1;k<=6;k++)
                {
                    if(i==1)
                    {
                        dp[i][j][j]=1;
                    }
                    else if(j==k)
                    {
                        dp[i][j][k]=0;
                    }
                    else if(i==2)
                    {
                        if(__gcd(j,k)==1 && j!=k)
                            dp[i][j][k]=1;
                    }
                    else {
                        if(__gcd(j,k)==1 && j!=k)
                        {
                            for(int d=1;d<=6;d++)
                            {
                                if(d==j)
                                    continue;
                                dp[i][j][k]+=dp[i-1][k][d];
                                dp[i][j][k]%=MOD;
                            }
                        }
                    }
                }
            }
        }
        
        for(int i=1;i<=6;i++)
        {
            for(int j=1;j<=6;j++)
            {
                ans+=dp[n][i][j];
                ans%=MOD;
            }
        }
        
        return ans;
        
    }
};