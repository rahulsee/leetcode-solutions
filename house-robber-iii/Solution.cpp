// https://leetcode.com/problems/house-robber-iii

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
    int rob(TreeNode* root) {
        if(root==NULL)
            return 0;
        if(root->left==NULL && root->right==NULL){
            return root->val;
        }
        int a=root->val;
        int b=0;
        int c=0;
        if(root->left)
            b=rob(root->left->left)+rob(root->left->right);
        if(root->right)
            c=rob(root->right->left)+rob(root->right->right);
        int d=rob(root->left);
        int e=rob(root->right);
        return max(a+b+c, d+e);
    }
};