// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void getpath(TreeNode* root, TreeNode *t,vector<TreeNode*> &path,vector<TreeNode*> &answer)
    {
        if(root==t)
        {
            answer=path;
            answer.push_back(t);
            return;
        }
        
        if(root==NULL)
            return;
        
        path.push_back(root);
        getpath(root->left,t,path,answer);
        getpath(root->right,t,path,answer);
        path.pop_back();
        
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>path1;
        vector<TreeNode*>path2;
        vector<TreeNode*>tmp;
        getpath(root,p,tmp,path1);
        tmp.clear();
        getpath(root,q,tmp,path2);
        int m=path1.size()-1;
        int n=path2.size()-1;
        for(int i=min(m,n);i>=0;i--)
        {
            if(path1[i]==path2[i])
                return path1[i];
        }
        return root;
    }
};