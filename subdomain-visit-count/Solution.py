// https://leetcode.com/problems/subdomain-visit-count

class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        ans = dict()
        for x in cpdomains:
            count, domain = tuple(x.split(" "))
            if domain in ans.keys():
                ans[domain] += int(count)
            else:
                ans[domain] = int(count)
        for x in cpdomains:
            count, domain = tuple(x.split(" "))
            for i,c in enumerate(domain):
                if c == '.':
                    parent = domain[i+1:]
                    if parent in ans.keys():
                        ans[parent] += int(count)
                    else:
                        ans[parent] = int(count)
        
        return [str(x)+" "+y for y, x in ans.items()]