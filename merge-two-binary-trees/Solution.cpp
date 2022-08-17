// https://leetcode.com/problems/merge-two-binary-trees

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode *root=NULL;
        if(t1==NULL && t2==NULL)
        {
            root=NULL;
            return root;
        }
        if(t1 && t2==NULL)
        {
           root=t1;
            return root;
        }
        if(t1==NULL && t2)
        {
            root=t2;
            return root;
        }
        root=new TreeNode(t1->val+t2->val);
        root->left=mergeTrees(t1->left,t2->left);
        root->right=mergeTrees(t1->right,t2->right);
        return root;
    }
    
};
