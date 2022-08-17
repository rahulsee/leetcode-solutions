// https://leetcode.com/problems/two-city-scheduling

class Solution {
public:
    
    int dp[101][101];
    
    int solve(vector<vector<int>>& costs,int cur,int A,int B)
    {
        if(dp[A][B]!=-1)
            return dp[A][B];
        
        if(cur==costs.size())
            return 0;
        
        if(A==costs.size()/2)
            dp[A][B]=costs[cur][1]+solve(costs,cur+1,A,B+1);
        else if(B==costs.size()/2)
            dp[A][B]=costs[cur][0]+solve(costs,cur+1,A+1,B);
        else{
            int p=costs[cur][0]+solve(costs,cur+1,A+1,B);
            int q=costs[cur][1]+solve(costs,cur+1,A,B+1);
            dp[A][B]=min(p,q);
        }
        return dp[A][B];
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        memset(dp,-1,sizeof(dp));
        return solve(costs,0,0,0);
    }
    
    
    
};