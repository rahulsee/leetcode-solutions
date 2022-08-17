// https://leetcode.com/problems/loud-and-rich

class Solution:
    
    def __init__(self):
        self.min_q = 0
        self.ans_node = 0
    
    def dfs(self, node, g, visited, quiet):
        visited.add(node)
        if quiet[node] < self.min_q:
            self.min_q = quiet[node]
            self.ans_node = node
            
        for c in g[node]:
            if c in visited:
                continue
            self.dfs(c, g, visited, quiet)
    
    def loudAndRich(self, richer: List[List[int]], quiet: List[int]) -> List[int]:
        n=len(quiet)
        g={i:[] for i in range(n)}
        ans=[]
        for q in richer:
            x,y = q[0],q[1]
            g[y].append(x)
        for i in range(n):
            visited = set()
            self.ans_node = i
            self.min_q = quiet[i]
            self.dfs(i, g, visited, quiet)
            ans.append(self.ans_node)
        return ans