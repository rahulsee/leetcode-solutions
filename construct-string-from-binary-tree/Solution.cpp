// https://leetcode.com/problems/construct-string-from-binary-tree

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
    
    string tree2str(TreeNode* t) {
        if(t==NULL)
            return "";
        if(t->left==NULL && t->right==NULL)
            return to_string(t->val);
        string ans=to_string(t->val);
        ans+="(";
        ans+=tree2str(t->left);
        ans+=")";
        if(t->right)
        {
            ans+="(";
            ans+=tree2str(t->right);
            ans+=")";
        }
        return ans;
    }
    
};