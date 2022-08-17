// https://leetcode.com/problems/binary-tree-level-order-traversal-ii

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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        Queue<TreeNode>q=new LinkedList<TreeNode>();
        q.add(root);
        List<List<Integer>>ans=new ArrayList<List<Integer> >();
        if(root==null)
            return ans;
        while(q.size()>0){
            
            ArrayList<TreeNode>tmp=new ArrayList<TreeNode>();
            ArrayList<Integer>lvl=new ArrayList<Integer>();
            
            while(q.size()>0){
                TreeNode f=q.peek();
                if(f.left!=null){
                    tmp.add(f.left);
                }
                if(f.right!=null){
                    tmp.add(f.right);
                }
                lvl.add(f.val);
                q.remove();
            }
            ans.add(lvl);
            
            for(TreeNode t:tmp){
                q.add(t);
            }
        }
        Collections.reverse(ans);
        return ans;
    }
}