// https://leetcode.com/problems/flip-string-to-monotone-increasing

class Solution:
    def minFlipsMonoIncr(self, s: str) -> int:
        seen_one=False
        a=0
        b=0
        c=0
        d=0
        for i, ch in enumerate(s):
            if ch=='0':
                a+=1
            if ch=='1':
                b=max(b+1, a+1)
        ls=max(a,b)
        return len(s)-ls