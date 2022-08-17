// https://leetcode.com/problems/increasing-order-search-tree

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    TreeNode node;
    TreeNode ans;
    public void solve(TreeNode root){
        if(root==null)
            return;
        TreeNode left=root.left;
        TreeNode right=root.right;
        root.left=null;
        root.right=null;
        solve(left);
        if(node==null){
            node=root;
            ans=node;
        }
        else{
            node.right=root;
            node=root;
        }
        solve(right);
    }
    public TreeNode increasingBST(TreeNode root) {
        solve(root);
        return ans;
    }
    
    
}