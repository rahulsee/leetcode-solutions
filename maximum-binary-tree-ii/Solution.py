// https://leetcode.com/problems/maximum-binary-tree-ii

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
    def insertIntoMaxTree(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        
        def insert_util(cur, parent, val):
            
            if cur == None:
                return TreeNode(val=val, left=None, right=None)
            
            if val > cur.val:
                new_node=TreeNode(val=val, left=cur, right=None)
                if parent == None:
                    new_node.left=cur
                elif cur == parent.left:
                    parent.left=new_node
                    new_node.left=cur
                else:
                    parent.right=new_node
                    new_node.left=cur
                return new_node
                    
            else:
                if cur.right == None:
                    cur.right = TreeNode(val=val)
                else:
                    cur.right = insert_util(cur.right, cur, val)
                return cur
        
        return insert_util(root, None, val)