// https://leetcode.com/problems/sum-root-to-leaf-numbers

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
    
    long long sum=0;
    void preorder(TreeNode *root,vector<int> &vec){
        vec.push_back(root->val);
        if(root->left==NULL && root->right==NULL)
        {
            long long prod=1;
            long long tot=0;
            for(int i=0;i<vec.size();i++){
                tot=tot*10+vec[i];
            }
            cout<<tot<<endl;
            sum+=tot;
            vec.pop_back();
            return;
        }
        
        if(root->left)
        {
            preorder(root->left,vec);
        }
        if(root->right)
        {
            preorder(root->right,vec);
        }
        vec.pop_back();
        
    }
    
    int sumNumbers(TreeNode* root) {
        if(root==NULL)
            return 0;
        vector<int>vec;
        preorder(root,vec);
        return sum;
    }
    
    
};