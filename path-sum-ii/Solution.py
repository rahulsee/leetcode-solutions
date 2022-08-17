// https://leetcode.com/problems/path-sum-ii

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
    def solve(self, root, run_sum, run_list, ans, is_parent_leaf):
        if run_sum==0 and root==None and is_parent_leaf:
            ans.append([r for r in run_list])
            return
        if root==None:
            return
        run_sum-=root.val
        run_list.append(root.val)
        if root.left==None and root.right==None:
            self.solve(None, run_sum, run_list, ans, True)
        else:
            self.solve(root.left, run_sum, run_list, ans, False)
            self.solve(root.right, run_sum, run_list, ans, False)
        run_list.pop()
        run_sum+=root.val
        
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        
        if root==None:
            return []
        
        run_list=[]
        run_sum=targetSum
        ans=[]
        self.solve(root, run_sum, run_list, ans, False)
        return ans