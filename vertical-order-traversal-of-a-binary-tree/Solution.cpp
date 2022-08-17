// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        unordered_map<TreeNode *, int>col;
        unordered_map<TreeNode *, int>row;  
        queue<TreeNode*>q;
        q.push(root);
        col[root]=0;
        row[root]=0;
        int minCol=numeric_limits<int>::max();
        int maxCol=numeric_limits<int>::min();
        int maxRow=numeric_limits<int>::min();
        vector<TreeNode*>vec;
        while(!q.empty()){
            TreeNode *node=q.front();
            minCol=min(minCol, col[node]);
            maxCol=max(maxCol, col[node]);
            maxRow=max(maxRow, row[node]);
            vec.push_back(node);
            q.pop();
            if(node->left) {
                q.push(node->left);
                col[node->left]=col[node]-1;
                row[node->left]=row[node]+1; 
            }
            if(node->right) {
                q.push(node->right);
                col[node->right]=col[node]+1;
                row[node->right]=row[node]+1;
            }
        }
        for(int i=0;i<vec.size();i++){
            for(int j=i+1;j<vec.size();j++){
                if(col[vec[i]]==col[vec[j]] && row[vec[i]]==row[vec[j]]){
                    if(vec[i]->val > vec[j]->val){
                        swap(vec[i], vec[j]);
                    }
                }
                else if(col[vec[i]]==col[vec[j]]){
                    if(row[vec[i]]>row[vec[j]])
                        swap(vec[i], vec[j]);
                }
                else if(col[vec[i]] > col[vec[j]]){
                    swap(vec[i], vec[j]);
                }
            }
        }
        vector<vector<int> >ans(maxCol-minCol+1);
        for(int i=0;i<vec.size();i++){
            ans[col[vec[i]]-minCol].push_back(vec[i]->val);
        }
        return ans;
    }
};