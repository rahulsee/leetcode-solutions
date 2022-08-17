// https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree

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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*>q1;
        queue<TreeNode*>q2;
        q1.push(original);
        q2.push(cloned);
        while(!q1.empty()){
            TreeNode *v1=q1.front();
            q1.pop();
            TreeNode *v2=q2.front();
            q2.pop();
            if(v1==target)
                return v2;
            if(v1->left){
                q1.push(v1->left);
                q2.push(v2->left);
            }
            if(v1->right){
                 q1.push(v1->right);
                q2.push(v2->right);
            }
        }
        return NULL;
    }
};