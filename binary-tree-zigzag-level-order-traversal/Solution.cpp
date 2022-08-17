// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        bool flag=false;
        while(!q.empty()){
            vector<TreeNode*>tmp;
            while(q.size()>0){
                tmp.push_back(q.front());
                q.pop();
            }
            vector<int>vec;
            for(TreeNode * node: tmp){
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
                vec.push_back(node->val);
            }
            if(flag){
                reverse(tmp.begin(), tmp.end());
                reverse(vec.begin(), vec.end());
            }
            flag=!flag;
            ans.push_back(vec);
        }
        return ans;
    }
};