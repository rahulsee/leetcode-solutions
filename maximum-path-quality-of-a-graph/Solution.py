// https://leetcode.com/problems/maximum-path-quality-of-a-graph

class Solution:
    def maximalPathQuality(self, values: List[int], edges: List[List[int]], maxTime: int) -> int:
        
        n=len(values)
        g=defaultdict(lambda: dict())
        visited=[0 for _ in range(len(values))]
        for e in edges:
            g[e[0]][e[1]]=g[e[1]][e[0]]=e[2]
        
        ans=[0]
        
        def dfs(node, val, time_taken):
            visited[node]+=1
            if node==0:
                ans[0]=max(ans[0], val)
            for ch, v in g[node].items():
                if v==0:
                    continue
                if v<=time_taken and visited[ch]==0:
                    dfs(ch, val+values[ch], time_taken-v)
                elif v<=time_taken and visited[ch]>0:
                    dfs(ch, val, time_taken-v)
            visited[node]-=1
        
        dfs(0, values[0], maxTime)
        return ans[0]
                    