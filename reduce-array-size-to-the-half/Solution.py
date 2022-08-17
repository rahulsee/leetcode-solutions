// https://leetcode.com/problems/reduce-array-size-to-the-half

class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        ctr=Counter(arr)
        target=ceil(len(arr)/2)
        ans=0
        for n,c in ctr.most_common():
            if c>=target:
                return ans+1
            if c<=target:
                target-=c
                ans+=1
        return ans