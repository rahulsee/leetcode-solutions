// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii

class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        s = sorted(nums)
        median = s[len(nums)//2]
        tot = 0
        for n in nums:
            tot+=abs(median-n)
        return tot