// https://leetcode.com/problems/word-break

class Solution:
    
    def solve(self, s, wordDict, memo, i):
        if memo[i]!=-1:
            return memo[i]
        res=False
        if i==len(s):
            return True
        start=i
        while i <= len(s):
            if s[start:i] in wordDict:
                res = res or self.solve(s, wordDict, memo, i)
            i+=1
        memo[start]=res
        return res
    
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        memo=defaultdict(lambda: -1)
        self.solve(s, wordDict, memo, 0)
        return memo[0]