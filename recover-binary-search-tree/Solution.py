// https://leetcode.com/problems/recover-binary-search-tree

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
    def inorder_traversal(self, root, in_list):
        if root==None:
            return
        self.inorder_traversal(root.left, in_list)
        in_list.append(root)
        self.inorder_traversal(root.right, in_list)
    
    def recoverTree(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        in_list=[]
        self.inorder_traversal(root, in_list)
        mismatches=[]
        for i in range(1, len(in_list)):
            if in_list[i].val < in_list[i-1].val:
                mismatches.append((in_list[i-1], in_list[i]))
        
        if len(mismatches)==1:
            mismatches[0][0].val,mismatches[0][1].val = mismatches[0][1].val, mismatches[0][0].val
        else:
            mismatches[0][0].val, mismatches[1][1].val=mismatches[1][1].val, mismatches[0][0].val
            