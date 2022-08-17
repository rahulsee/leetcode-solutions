// https://leetcode.com/problems/restore-ip-addresses

class Solution:
    
    def solve(self, s, new_ip, dot_count, cur, ans):
        if cur==len(s):
            if dot_count==-1:
                ans.append(".".join(new_ip))
            return
                
        if len(new_ip)==0 or len(new_ip[-1])==3 or new_ip[-1][0]=='0':
            if dot_count>=0:
                new_ip.append(s[cur])
                self.solve(s, new_ip, dot_count-1, cur+1, ans)
                new_ip.pop()
        
        else:
            num=new_ip[-1]+s[cur]
            if int(num)<=255:
                temp=new_ip[-1]
                new_ip[-1]=num
                self.solve(s, new_ip, dot_count, cur+1, ans)
                new_ip[-1]=temp
                
                if dot_count>=0:
                    new_ip.append(s[cur])
                    self.solve(s, new_ip, dot_count-1, cur+1, ans)
                    new_ip.pop()
            else:
                if dot_count>=0:
                    new_ip.append(s[cur])
                    self.solve(s, new_ip, dot_count-1, cur+1, ans)
                    new_ip.pop()
        
    def restoreIpAddresses(self, s: str) -> List[str]:
        
        if len(s)<4:
            return []
        
        new_ip=[]
        dot_count=3
        cur=0
        ans=[]
        self.solve(s, new_ip, dot_count, cur, ans)
        return ans