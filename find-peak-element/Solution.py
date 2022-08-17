// https://leetcode.com/problems/find-peak-element

class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        l=0
        r=len(nums)-1
        if len(nums)==1:
            return 0
        while l <= r:
            mid=(l+r)//2
            if (mid-1)>=0 and (mid+1) < len(nums) and nums[mid]>nums[mid+1] and nums[mid]>nums[mid-1]:
                return mid
            elif mid==len(nums)-1 and (mid-1)>=0 and nums[mid]>nums[mid-1]:
                return mid
            elif mid==0 and (mid+1)<len(nums) and nums[mid]>nums[mid+1]:
                return mid
            else:
                if (mid-1)>=0 and nums[mid-1]>nums[mid]:
                    r=mid-1
                elif (mid+1)<len(nums) and nums[mid+1]>nums[mid]:
                    l=mid+1
        return mid