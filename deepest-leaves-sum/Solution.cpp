// https://leetcode.com/problems/deepest-leaves-sum

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
    int deepestLeavesSum(TreeNode* root) {
        if(root==NULL)
            return 0;
        int ans=root->val;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<TreeNode*>vec;
            int sum=0;
            while(q.size()>0){
                vec.push_back(q.front());
                sum+=q.front()->val;
                q.pop();
            }
            for(TreeNode* t: vec) {
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
            ans=sum;
        }
        return ans;
    }
};