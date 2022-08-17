// https://leetcode.com/problems/paint-house-iii

class Solution:
    def minCost(self, houses: List[int], cost: List[List[int]], m: int, n: int, target: int) -> int:
                
        dp=[[[-1 for _ in range(target+1)] for _ in range(n+1)] for _ in range(m)]
        def solve(cur_house, prev_color, t):
            
            if cur_house==m and t>0:
                return int(10**9)+7
            
            if cur_house==m and t==0:
                return 0
            
            
            if dp[cur_house][prev_color][t] > 0:
                return dp[cur_house][prev_color][t]
            
            ans=int(10**9)+7
            if houses[cur_house]==0:
                for i in range(1, n+1):
                    if i==prev_color:
                        continue
                    if t>0:
                        ans=min(ans, solve(cur_house+1, i, t-1)+cost[cur_house][i-1])
                
                if prev_color>0:
                    ans=min(ans, solve(cur_house+1, prev_color, t)+cost[cur_house][prev_color-1])
            else:
                if houses[cur_house]==prev_color:
                    ans=min(ans, solve(cur_house+1, prev_color, t))
                elif t>0:
                    ans=min(ans, solve(cur_house+1, houses[cur_house], t-1))
            
            dp[cur_house][prev_color][t]=ans
            return ans
                    
        ans=solve(0,0,target)
        if ans>=int(10**9)+7:
            return -1
        return ans