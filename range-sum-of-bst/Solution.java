// https://leetcode.com/problems/range-sum-of-bst

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
    ArrayList<Integer>inorder;
    
    public void traverse(TreeNode root, int low, int high){
        if(root==null)
            return;
        traverse(root.left, low, high);
        inorder.add(root.val);
        traverse(root.right, low, high);
    }
    
    public int rangeSumBST(TreeNode root, int low, int high) {
        if(root==null){
            return 0;
        }
        inorder=new ArrayList<>();
        inorder.add(0);
        traverse(root, low, high);
        int pSum[]=new int[inorder.size()];
        pSum[0]=inorder.get(0);
        for(int i=1;i<inorder.size();i++){
            pSum[i]=pSum[i-1]+inorder.get(i);
        }
        
        int count=0;
        int lowIndex=-1;
        int highIndex=-1;
        for(int v: inorder){
            if(v >= low && lowIndex<0)
                lowIndex=count;
            if(v>=high && highIndex < 0)
                highIndex=count;
            count++;
        }
        if(lowIndex==-1 || highIndex==-1)
            return -1;
        return pSum[highIndex]-pSum[lowIndex-1];
    }
}