// https://leetcode.com/problems/number-of-different-subsequences-gcds

class Solution:
    def countDifferentSubsequenceGCDs(self, nums: List[int]) -> int:
        m=max(nums)
        s=set(nums)
        cnt=0
        for i in range(1, m+1):
            g=0
            for j in range(i, m+1, i):
                if j in s:
                    g=math.gcd(g, j)
            if g==i:
                cnt+=1
        return cnt
                    