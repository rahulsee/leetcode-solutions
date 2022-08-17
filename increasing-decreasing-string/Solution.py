// https://leetcode.com/problems/increasing-decreasing-string

class Solution:
    def sortString(self, s: str) -> str:
        counter=Counter(s)
        ans=[]
        while len(counter) > 0:
            keys=list(counter.keys())
            keys.sort()
            rare_ch, rare_count=counter.most_common()[-1]
            st=''
            st=''.join(keys)
            for i in range(rare_count):
                ans.append(st)
            for i in range(len(counter)):
                counter[keys[i]]-=rare_count
                if counter[keys[i]]==0:
                    del counter[keys[i]]
            
                
        ans_str=''
        for i,a in enumerate(ans):
            if i%2==1:
                ans_str+=a[::-1]
            else:
                ans_str+=a
        return ans_str