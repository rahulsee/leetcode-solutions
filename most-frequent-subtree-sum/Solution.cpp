// https://leetcode.com/problems/most-frequent-subtree-sum

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
    
    int solve(TreeNode *root,unordered_map<int,int> &freq)
    {
        if(root==NULL)
            return 0;
        root->val=solve(root->left,freq)+solve(root->right,freq)+root->val;
        freq[root->val]++;
        return root->val;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int>freq;
        solve(root,freq);
        int maxfreq=0;
        for(auto it=freq.begin();it!=freq.end();it++)
        {
            maxfreq=max(maxfreq,it->second);
        }
        vector<int>answer;
        for(auto it=freq.begin();it!=freq.end();it++)
        {
            if(it->second==maxfreq)
                answer.push_back(it->first);
        }
        return answer;
    }
};