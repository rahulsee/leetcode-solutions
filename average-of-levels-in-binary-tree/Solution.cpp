// https://leetcode.com/problems/average-of-levels-in-binary-tree

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
    vector<double> averageOfLevels(TreeNode* root) {
        if(root==NULL){
            vector<double>ans;
            return ans;
        }
        queue<TreeNode*>q;
        vector<double>ans;
        q.push(root);
        while(!q.empty()){
            double sum=0;
            double cnt=q.size();
            vector<TreeNode*>tmp;
            while(!q.empty()){
                sum+=q.front()->val;
                tmp.push_back(q.front());
                q.pop();
            }
            for(int i=0;i<tmp.size();i++){
                if(tmp[i]->left){
                    q.push(tmp[i]->left);
                }
                if(tmp[i]->right){
                    q.push(tmp[i]->right);
                }
            }
            ans.push_back(sum/cnt);
        }
        return ans;
    }
};