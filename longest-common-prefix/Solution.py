// https://leetcode.com/problems/longest-common-prefix

class Solution:
    
    def match_point(self, x,y):
        for idx, (i,j) in enumerate(zip(x,y)):
            if i!=j:
                return idx
        return min(len(x),len(y))
    
    def longestCommonPrefix(self, strs: List[str]) -> str:
        maxi=0
        for s in strs:
            maxi=max(maxi, len(s))
        low=0
        high=maxi
        ans=0
        while low <= high:
            mid=ceil(low+(high-low)/2)
            pref=strs[0][0:mid]
            mini=mid
            for s in strs:
                mini=min(mini, self.match_point(pref, s))
            if mini == mid:
                low=mid+1
            else:
                high=mini
            ans=max(ans, mini)
        return strs[0][0:ans]