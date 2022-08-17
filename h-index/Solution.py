// https://leetcode.com/problems/h-index

class Solution:
    def hIndex(self, citations: List[int]) -> int:
        citations=sorted(citations)
        n=len(citations)
        h_i=int(citations[0]!=0)
        for i, c in enumerate(citations):
            h_i=max(min(c, n-i), h_i)
        return h_i