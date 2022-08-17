// https://leetcode.com/problems/closest-dessert-cost

class Solution:

    def solve(self, b, topping, target, rsum, mindiff, ans, cur):
        
        if abs(rsum-target) < mindiff[0]:
            ans[0]=rsum
            mindiff[0]=abs(rsum-target)
        elif abs(rsum-target) == mindiff[0]:
            ans[0]=min(ans[0], rsum)

        if cur >= len(topping):
            return
        
        self.solve(b, topping, target, rsum+topping[cur], mindiff, ans, cur+1)
        self.solve(b, topping, target, rsum+2*topping[cur], mindiff, ans, cur+1)
        self.solve(b, topping, target, rsum, mindiff, ans, cur+1)
    
    
    def closestCost(self, baseCosts: List[int], toppingCosts: List[int], target: int) -> int:
        n=len(toppingCosts)
                
        final_diff=int(10**7)
        final_ans=int(10**7)
        
        for b in baseCosts:
            rsum=b
            ans=[int(10**7)]
            mindiff=[int(10**7)]
            cur=0
            self.solve(b, toppingCosts, target, rsum, mindiff, ans, cur)
            if mindiff[0] < final_diff:
                final_ans=ans[0]
                final_diff=mindiff[0]
            elif mindiff[0] == final_diff:
                final_ans=min(ans[0], final_ans)
        
        return final_ans