// https://leetcode.com/problems/maximum-width-of-binary-tree

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
    
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<TreeNode*>q;
        q.push(root);
        unordered_map<TreeNode*,long long>number;
        number[root]=0;
        long long maxi=0;
        while(!q.empty())
        {
            long long numnodes=q.size();
            long long lm=0,rm=0;
            int offset;
            for(int i=0;i<numnodes;i++)
            {
                TreeNode *v=q.front();
                q.pop();
                if(i==0)
                {
                    lm=number[v];
                    offset=number[v];
                }
                else if(i==numnodes-1)
                {
                    rm=number[v];
                }
                if(v->left)
                {
                    q.push(v->left);
                    number[v->left]=2*(number[v]-offset)+1;
                }
                if(v->right)
                {
                    q.push(v->right);
                    number[v->right]=2*(number[v]-offset)+2;
                }
            }
            maxi=max(maxi,rm-lm+1);
            
        }
        return maxi;
        
    }
};