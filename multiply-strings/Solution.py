// https://leetcode.com/problems/multiply-strings

class Solution:
    
    def karatsuba(self, x, y):
        if len(x)==1 or len(y)==1:
            return str(int(x)*int(y))
        x,y=self.pad(x,y)
        n=len(x)
        a=self.karatsuba(x[:n//2], y[:n//2])
        b=self.karatsuba(x[n//2:], y[n//2:])
        c=self.add(x[:n//2], x[n//2:])
        d=self.add(y[:n//2], y[n//2:])
        temp1=self.karatsuba(c,d)
        temp2=self.add(a,b)
        e=self.subtract(temp1, temp2)
        ans=self.add(a+("0"*n), e+("0"*(n//2)))
        ans=self.add(ans, b)
        return ans
    
    def add(self, x1, y1):
        x,y=self.pad(x1, y1)
        c=0
        r=0
        ans=''
        for a,b in zip(reversed(x),reversed(y)):
            t=int(a)+int(b)+c
            r=t%10
            c=t//10
            ans=str(r)+ans
        if c!=0:
            ans=str(c)+ans
        return ans
    
    def subtract(self, x1, y1):
        x,y=self.pad(x1, y1)
        c=0
        r=0
        ans=''
        for a,b in zip(reversed(x),reversed(y)):
            t=int(a)-int(b)+c
            r=(t+10)%10
            c=floor(t/10)
            ans=str(r)+ans
        return ans
    
    def pad(self, x, y):
        a=len(x)
        b=len(y)
        m=max(a,b)
        m=int(2**ceil(math.log2(m)))
        x=x.zfill(m)
        y=y.zfill(m)
        return x,y
        
    def multiply(self, num1: str, num2: str) -> str:
        num1, num2 = self.pad(num1, num2)
        ans=self.karatsuba(num1, num2).lstrip('0')
        if ans=="":
            return "0"
        return ans