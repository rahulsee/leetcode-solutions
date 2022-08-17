// https://leetcode.com/problems/binary-tree-tilt

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
    
    Map<TreeNode, Integer>nodeSums;
    public int calcTilt(TreeNode node){
        if(node.left==null && node.right==null)
            return 0;
        else if(node.right==null)
            return Math.abs(nodeSums.get(node.left));
        else if(node.left==null)
            return Math.abs(nodeSums.get(node.right));
        else
            return Math.abs(nodeSums.get(node.left) - nodeSums.get(node.right));
    }
    
    public int calcSum(TreeNode node){
        if(node==null)
            return 0;
        int s=calcSum(node.left)+calcSum(node.right)+node.val;
        nodeSums.put(node,s);
        return s;
    }
    
    public int findTilt(TreeNode root) {
        if(root==null)
            return 0;
        Queue<TreeNode>q=new LinkedList<>();
        nodeSums=new HashMap<>();
        calcSum(root);
         q.add(root);
        int sum=0;
        while(!q.isEmpty()){
            TreeNode node=q.remove();
            int t=calcTilt(node);
            sum+=t;
            if(node.left!=null){
                q.add(node.left);
            }
            if(node.right!=null) {
                q.add(node.right);
            }
        }
        return sum;
    }
}