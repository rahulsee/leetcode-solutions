// https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced

class Solution:
    def minSwaps(self, s: str) -> int:
        stack=[]
        count=0
        for ch in s:
            if ch==']' and len(stack)==0:
                stack.append('[')
                count+=1
            elif ch==']':
                stack.pop()
            else:
                stack.append(ch)
        return count