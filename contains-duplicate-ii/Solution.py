// https://leetcode.com/problems/contains-duplicate-ii

class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        if len(nums)==1:
            return False
        if k==0:
            return False
        val_dict=defaultdict(lambda: 0)
        for i in range(min(k+1, len(nums))):
            val_dict[nums[i]]+=1
            if val_dict[nums[i]]>=2:
                return True
        for i in range(min(k+1,len(nums)), len(nums)):
            val_dict[nums[i-k-1]]-=1
            val_dict[nums[i]]+=1
            if val_dict[nums[i]]>=2:
                return True
        return False
        
        
                