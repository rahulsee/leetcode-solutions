// https://leetcode.com/problems/target-sum

class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        nums=[0]+nums
        L = len(nums)
        dp = [dict() for i in range(L)]
        for i in range(L):
            for j in range(-1000, 1001):
                dp[i][j]=0
        
        dp[0][0]=1
        
        run_sum = 0
        for i in range(1,L):
            for j in range(-run_sum, run_sum+1):
                dp[i][j+nums[i]]+=dp[i-1][j]
                dp[i][j-nums[i]]+=dp[i-1][j]
            
            run_sum+=nums[i]
        
        return dp[L-1][target]