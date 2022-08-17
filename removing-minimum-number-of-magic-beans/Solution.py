// https://leetcode.com/problems/removing-minimum-number-of-magic-beans

class Solution:
    def minimumRemoval(self, nums: List[int]) -> int:
        if len(nums)==1:
            return 0
        nums=sorted(nums)
        x=nums[:]
        y=x[:]
        for i in range(1,len(x)):
            x[i]+=x[i-1]
        for i in range(len(y)-2, -1, -1):
            y[i]+=y[i+1]
    
        
        ans=int(10**10)
        n=len(x)
        for i in range(n):
            if i==0:
                cost=y[i+1]-nums[0]*(n-i-1)
            elif i==n-1:
                cost=x[i-1]
            else:
                cost=x[i-1]+(y[i+1]-nums[i]*(n-i-1))
            ans=min(ans, cost)
        return ans