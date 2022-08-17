// https://leetcode.com/problems/restore-the-array-from-adjacent-pairs

class Solution:
    def restoreArray(self, adjacentPairs: List[List[int]]) -> List[int]:
        g = dict()
        for p in adjacentPairs:
            x,y = tuple(p)
            if x in g.keys():
                g[x].append(y)
            else:
                g[x]=[y]
            if y in g.keys():
                g[y].append(x)
            else:
                g[y]=[x]
        
        
        q=collections.deque()
        root = None
        for k,v in g.items():
            if len(v) == 1:
                root=k
                break
        
        if root == None:
            return []
        
        q.append(root)
        visited=set()
        visited.add(root)
        ans=[]
        while len(q) > 0:
            node=q.popleft()
            ans.append(node)
            for c in g[node]:
                if c in visited:
                    continue
                visited.add(c)
                q.append(c)
            
        return ans