// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum

class Solution {
public:
    
    int f;
    int dp[1007][37];
    
    int solve(int s, int d){
        if(dp[s][d]!=-1)
            return dp[s][d];
        if(s==0 && d==0){
            dp[s][d]=1;
            return 1;
        }
        else if(s>0 && d==0){
            dp[s][d]=0;
            return 0;
        }
        else if(s==0 && d>0){
            dp[s][d]=0;
            return 0;
        }
        int ans=0;
        for(int i=1;i<=f;i++){
            if(s>=i){
                ans=(ans+solve(s-i, d-1))%1000000007;
            }
        }
        dp[s][d]=ans;
        return dp[s][d];
    }
    
    int numRollsToTarget(int d, int f, int target) {
        this->f=f;
        for(int i=0;i<1007;i++){
            for(int j=0;j<37;j++){
                dp[i][j]=-1;
            }
        }
        solve(target,d);
        return dp[target][d];
    }
};