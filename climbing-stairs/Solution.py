// https://leetcode.com/problems/climbing-stairs

class Solution:
    def climbStairs(self, n: int) -> int:
        if n==1 or n==0:
            return 1
        stairs=[0]*(n+1)
        stairs[0]=1
        stairs[1]=1
        for i in range(2, n+1):
            stairs[i]=stairs[i-1]+stairs[i-2]
        return stairs[n]