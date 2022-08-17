// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

class Solution:
    
    def solve(self, nums, left, right, ans):
        mid=(left+right)//2
    
        if mid<0 or mid>=len(nums) or left > right:
            return
                
        ans[0]=min(ans[0], nums[mid])
        
        if left==right:
            return
        
        if mid>=1 and nums[mid] < nums[mid-1]:
            self.solve(nums, mid+1, right, ans)
        elif (mid+1)<len(nums) and nums[mid] > nums[mid+1]:
            self.solve(nums, mid+1, right, ans)
        elif nums[0] > nums[-1]:
            if nums[mid]<nums[0]:
                self.solve(nums, left, mid, ans)
            else:
                self.solve(nums, mid, right, ans)
        elif nums[0] < nums[-1]:
            if nums[mid]<nums[0]:
                self.solve(nums, mid, right, ans)
            else:
                self.solve(nums, left, mid, ans)
                
    
    def findMin(self, nums: List[int]) -> int:
        ans=[int(10**7)]
        self.solve(nums, 0, len(nums)-1, ans)
        return ans[0]