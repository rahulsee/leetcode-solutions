// https://leetcode.com/problems/unique-binary-search-trees-ii

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
    
    
    vector<TreeNode*> solve(int x, int y){
        if((y-x)==1){
            TreeNode *p=new TreeNode(x);
            TreeNode *q=new TreeNode(y);
            TreeNode *r=new TreeNode(x);
            TreeNode *s=new TreeNode(y);
            p->right=q;
            s->left=r;
            vector<TreeNode*>vec;
            vec.push_back(p);
            vec.push_back(s);
            return vec;
        }
        
        if(y==x){
            TreeNode *p=new TreeNode(x);
            vector<TreeNode*>vec;
            vec.push_back(p);
            return vec;
        }
        
        if(x>y){
            vector<TreeNode*>vec;
            return vec;
        }
    
        vector<TreeNode*>ans;
        
        for(int i=x;i<=y;i++){
            vector<TreeNode*>lc=solve(x, i-1);
            if(lc.size()==0)
                lc.push_back(NULL);
            vector<TreeNode*>rc=solve(i+1,y);
            if(rc.size()==0)
                rc.push_back(NULL);
            for(int p=0;p<lc.size();p++){
                for(int q=0;q<rc.size();q++){
                    TreeNode *root=new TreeNode(i);
                    root->left=lc[p];
                    root->right=rc[q];
                    ans.push_back(root);
                }
            }
        }
        
        return ans;
        
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};