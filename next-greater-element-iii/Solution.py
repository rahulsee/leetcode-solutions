// https://leetcode.com/problems/next-greater-element-iii

class Solution:
    def nextGreaterElement(self, n: int) -> int:
        a=str(n)
        a=list(map(int, a))
        flag=False
        for i in range(len(a)-2,-1,-1):
            if a[i] < a[i+1]:
                flag=True
                break
        if not flag or n>2147483647:
            return -1
        pivot=i
        swapper=pivot
        min_diff=10
        for j in range(pivot+1, len(a)):
            if a[j]>a[pivot] and (a[j]-a[pivot])<min_diff:
                min_diff=a[j]-a[pivot]
                swapper=j
        a[pivot], a[swapper]=a[swapper], a[pivot]
        a[pivot+1:]=sorted(a[pivot+1:])
        next_one=int(''.join([str(x) for x in a]))
        if next_one > 2147483647:
            return -1
        return next_one