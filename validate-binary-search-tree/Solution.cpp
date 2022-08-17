// https://leetcode.com/problems/validate-binary-search-tree

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
    
    void inorder(TreeNode *root,vector<int>&tr)
    {
        if(root==NULL)
            return;
        inorder(root->left,tr);
        tr.push_back(root->val);
        inorder(root->right,tr);
    }
    
    bool isValidBST(TreeNode* root) {
        vector<int>tr;
        inorder(root,tr);
        for(int i=1;i<tr.size();i++)
        {
            if(tr[i]<=tr[i-1])
                return false;
        }
        return true;
    }
};