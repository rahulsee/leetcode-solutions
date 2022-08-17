// https://leetcode.com/problems/binary-search-tree-iterator

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
class BSTIterator {
public:
    
    vector<int>inorder;
    int cur=0;
    
    void inorder_traverse(TreeNode *root){
        if(root==NULL)
            return;
        inorder_traverse(root->left);
        inorder.push_back(root->val);
        inorder_traverse(root->right);
    }
    
    BSTIterator(TreeNode* root) {
        inorder_traverse(root);
    }
    
    /** @return the next smallest number */
    int next() {
        if(cur < inorder.size())
        {    
            int ans=inorder[cur];
            cur++;
            return ans;
        }
        return -1;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return cur < inorder.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */