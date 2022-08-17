// https://leetcode.com/problems/constrained-subsequence-sum

class Solution:
    def constrainedSubsetSum(self, nums: List[int], k: int) -> int:
        arr=[]
        ans=-(10**9)
        for i,n in enumerate(nums):
            while len(arr)>0 and i-arr[0][1]>k:
                    ans=max(ans, -arr[0][0])
                    heapq.heappop(arr)
                    
            if len(arr)>0 and (-arr[0][0]+nums[i])>=nums[i]:
                heapq.heappush(arr, (arr[0][0]-nums[i],i))
                ans=max(ans, -arr[0][0])
            else:
                heapq.heappush(arr, (-nums[i],i))
                ans=max(ans, -arr[0][0])
        return ans