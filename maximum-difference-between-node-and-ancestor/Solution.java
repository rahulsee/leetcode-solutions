// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor

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
    
    HashMap<TreeNode, Integer>max;
    HashMap<TreeNode, Integer>min;
    
    public int findMax(TreeNode root){
        if(root==null)
            return Integer.MIN_VALUE;
        
        if(root.left==null && root.right==null){
            return root.val;
        }
        int leftMax=findMax(root.left);
        int rightMax=findMax(root.right);
        max.put(root, Math.max(leftMax,rightMax));
        return Math.max(root.val, max.get(root));
    }
    
    public int findMin(TreeNode root){
        if(root==null)
            return Integer.MAX_VALUE;
        
        if(root.left==null && root.right==null){
            return root.val;
        }
        int leftMin=findMin(root.left);
        int rightMin=findMin(root.right);
        min.put(root, Math.min(leftMin,rightMin));
        return Math.min(root.val, min.get(root));
    }
    
    public int maxAncestorDiff(TreeNode root) {
        max=new HashMap<>();
        min=new HashMap<>();
        findMax(root);
        findMin(root);
        int maxDiff=Integer.MIN_VALUE;
        for(TreeNode key: max.keySet()){
            int a=Math.abs(key.val - min.get(key));
            int b=Math.abs(key.val - max.get(key));
            maxDiff=Math.max(a,Math.max(b, maxDiff));
        }
        return maxDiff;
    }
}