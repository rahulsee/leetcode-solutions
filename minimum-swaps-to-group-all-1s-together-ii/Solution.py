// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii

class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        ones=nums.count(1)
        nums=nums+nums
        i=0
        zeros=0
        while i < ones:
            if nums[i]==0:
                zeros+=1
            i+=1
        ans=zeros
        while i < len(nums):
            if nums[i-ones]==0:
                zeros-=1
            if nums[i]==0:
                zeros+=1
            ans=min(ans, zeros)
            i+=1
        return ans
        