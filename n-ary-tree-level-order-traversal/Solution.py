// https://leetcode.com/problems/n-ary-tree-level-order-traversal

"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        q = []
        q.append(root)
        ans=[]
        if root is None:
            return ans
        while len(q)>0:
            new_q = []
            l_ans = []
            for node in q:
                for c in node.children:
                    new_q.append(c)
                l_ans.append(node.val)
            ans.append(l_ans)
            q = new_q
            
        return ans