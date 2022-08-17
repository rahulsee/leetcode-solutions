// https://leetcode.com/problems/heaters

class Solution:
    
    def search_gte(self, key, heaters):
        low=0
        high=len(heaters)-1
        ans=10**10+7
        while low<=high:
            mid=(low+high)//2
            if key>heaters[mid]:
                low=mid+1
            else:
                ans=min(ans, heaters[mid])
                high=mid-1
        return ans
    
    def search_lte(self, key, heaters):
        low=0
        high=len(heaters)-1
        ans=(-10**10-7)
        while low<=high:
            mid=(low+high)//2
            if key<heaters[mid]:
                high=mid-1
            else:
                ans=max(ans, heaters[mid])
                low=mid+1
        return ans
    
    def findRadius(self, houses: List[int], heaters: List[int]) -> int:
        max_req=0
        heaters=sorted(heaters)
        for h in houses:
            a=self.search_gte(h, heaters)
            b=self.search_lte(h, heaters)
            max_req=max(max_req, min(abs(a-h), abs(b-h)))
        return max_req