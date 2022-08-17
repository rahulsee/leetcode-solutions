// https://leetcode.com/problems/rotate-array

class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        k=k%len(nums)
        if k==0:
            return
        
        n=len(nums)-k
        for i in range(ceil(n//2)):
            nums[i],nums[n-i-1]=nums[n-i-1], nums[i]
        
        i=n
        j=len(nums)-1

        while i<=j:
            nums[i], nums[j]=nums[j], nums[i]
            i+=1
            j-=1
        
        i=0
        j=len(nums)-1
        
        while i<=j:
            nums[i], nums[j]=nums[j], nums[i]
            i+=1
            j-=1
        