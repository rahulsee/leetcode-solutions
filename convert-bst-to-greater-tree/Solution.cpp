// https://leetcode.com/problems/convert-bst-to-greater-tree

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
    vector<TreeNode*>vec;
    
    void inorder(TreeNode *root){
        if(root==NULL)
            return; 
        inorder(root->left);
        vec.push_back(root);
        inorder(root->right);
    }
    
    
    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL)
            return root;
        inorder(root);
        for(int i=vec.size()-2;i>=0;i--){
            vec[i]->val+=vec[i+1]->val;
        }
        return root;
    }
};