// https://leetcode.com/problems/evaluate-reverse-polish-notation

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack=[]
        for t in tokens:
            if t in ('+', '-', '*', '/'):
                a=stack.pop()
                b=stack.pop()
                if t=='+':
                    # print(f"Pushing {b+a}")
                    stack.append(b+a)
                elif t=='-':
                    # print(f"Pushing {b-a}")
                    stack.append(b-a)
                elif t=='*':
                    # print(f"Pushing {b*a}")
                    stack.append(b*a)
                else:
                    if (a*b) < 0:
                        stack.append(-(abs(b)//abs(a)))
                    else:
                        stack.append(b//a)
            else:
                stack.append(int(t))
        return stack.pop()