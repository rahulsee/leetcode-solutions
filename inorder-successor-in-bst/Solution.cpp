// https://leetcode.com/problems/inorder-successor-in-bst

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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode *par=NULL;
        TreeNode *r=root;
        while(r!=NULL && r!=p){
            if(p->val > r->val)
                r=r->right;
            else {
                par=r;
                r=r->left;
            }
        }
        TreeNode *x=par;
        TreeNode *y=NULL;
        if(p->right!=NULL){
            p=p->right;
            y=p;
            while(y->left!=NULL){
                y=y->left;
            }
        }
        if(x==NULL)
            return y;
        if(y==NULL)
            return x;
        if(x->val < y->val)
            return x;
        return y;
    }
};