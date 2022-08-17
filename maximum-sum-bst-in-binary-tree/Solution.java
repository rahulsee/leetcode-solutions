// https://leetcode.com/problems/maximum-sum-bst-in-binary-tree

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
    
     
    HashMap<TreeNode,Integer>sum;
    HashMap<TreeNode,Boolean>isBST;
    HashMap<TreeNode,Integer>min;
    HashMap<TreeNode,Integer>max;

    
    public int minUtil(TreeNode root){
        if(root==null){
            return Integer.MAX_VALUE;
        }
        int mini=Math.min(Math.min(minUtil(root.left),minUtil(root.right)),root.val);
        min.put(root,mini);
        return mini;
    }
  
    
    public int maxUtil(TreeNode root){
        if(root==null){
            return Integer.MIN_VALUE;
        }

        int maxi=Math.max(Math.max(maxUtil(root.left),maxUtil(root.right)),root.val);
        max.put(root,maxi);
        return maxi;
    }
    
    public int sumUtil(TreeNode root){
        if(root==null){
            return 0;
        }
        int tot=sumUtil(root.left)+sumUtil(root.right)+root.val;
        sum.put(root,tot);
        return tot;
        
    }
    
    public boolean isBSTUtil(TreeNode root){
        if(root==null)
            return true;
        boolean a=isBSTUtil(root.left);
        boolean b=isBSTUtil(root.right);
        Integer lm=(root.left!=null)?max.get(root.left):Integer.MIN_VALUE;
        Integer rmi=(root.right!=null)?min.get(root.right):Integer.MAX_VALUE;
        if(lm < root.val && rmi > root.val && a && b)
        {
            isBST.put(root,true);
            return true;
        }
        else{
            isBST.put(root,false);
            return false;
        }
    }
    
    public int maxSumBST(TreeNode root) {
        isBST=new HashMap<TreeNode,Boolean>();
        sum=new HashMap<TreeNode,Integer>();
        min=new HashMap<TreeNode,Integer>();
        max=new HashMap<TreeNode,Integer>();
        sumUtil(root);
        minUtil(root);
        maxUtil(root);
        isBSTUtil(root);
        
        int maxsum=Integer.MIN_VALUE;
        
        for(TreeNode t:isBST.keySet()){
            System.out.println(t.val+" "+sum.get(t));
            if(isBST.get(t)==true){
                System.out.println(sum.get(t));
                maxsum=Math.max(sum.get(t),maxsum);
            }
        }
        
        if(maxsum <0)
            maxsum=0;
        return maxsum;
    }
    
    
    
}