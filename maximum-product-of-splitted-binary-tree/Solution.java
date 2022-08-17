// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree

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
    
    HashMap<TreeNode,Long>sum;
    long ans=0;
    int MOD=(int)Math.pow(10,9)+7;
    TreeNode treeRoot;
    
    public long sumTree(TreeNode root){
        if(root==null)
            return 0;
        long tmp=sumTree(root.left)+sumTree(root.right);
        tmp=tmp+root.val;
        sum.put(root,tmp);
        return tmp;
    }
    
    public int maxProduct(TreeNode root) {
        sum=new HashMap<TreeNode,Long>();
        sumTree(root);
        for(TreeNode t:sum.keySet()){
            long tmp=(sum.get(root)-sum.get(t));
            tmp=(tmp*sum.get(t));
            ans=Math.max(tmp,ans);
        }
        return (int)(ans%(int)MOD);
    }
}