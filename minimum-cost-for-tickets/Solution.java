// https://leetcode.com/problems/minimum-cost-for-tickets

class Solution {
    
    public int mincostTickets(int[] days, int[] costs) {
        int dp[]=new int[400];
        boolean flag[]=new boolean[400];
        for(int i=0;i<days.length;i++)
            flag[days[i]]=true;
        for(int i=1;i<400;i++){
            if(flag[i]){
                dp[i]=Math.min(
                    dp[Math.max(i-1,0)]+costs[0],
                    Math.min(
                        dp[Math.max(i-7,0)]+costs[1],
                        dp[Math.max(i-30,0)]+costs[2]
                    )
                );
            }
            else
            {
                dp[i]=dp[i-1];
            }
            
        }
        return dp[399];
        
    }
}