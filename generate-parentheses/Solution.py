// https://leetcode.com/problems/generate-parentheses

class Solution:
    
    def solve(self, final_ans, ans, n, open_p, closed_p):
                
        if open_p == closed_p and len(ans)==2*n:
            final_ans.append(''.join(ans))
            return
        
        if open_p < n and open_p>=closed_p:
            ans.append('(')
            self.solve(final_ans, ans, n, open_p+1, closed_p)
            ans.pop()
        
        if closed_p < n and open_p >= closed_p:
            ans.append(')')
            self.solve(final_ans, ans, n, open_p, closed_p+1)
            ans.pop()
    
    def generateParenthesis(self, n: int) -> List[str]:
        
        ans=[]
        final_ans=[]
        open_p=0
        closed_p=0
        self.solve(final_ans, ans, n, open_p, closed_p)
        return final_ans