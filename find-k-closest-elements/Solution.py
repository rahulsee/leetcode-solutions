// https://leetcode.com/problems/find-k-closest-elements

class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        h=[]
        heapq.heapify(h)
        for a in arr:
            tup=(-abs(a-x), -a)
            if len(h) < k:
                heapq.heappush(h, tup)
            else:
                if tup > h[0]:
                    heapq.heappop(h)
                    heapq.heappush(h, tup)
        
        h=list(h)
        ans=[-a[1] for a in h]
        return sorted(ans)