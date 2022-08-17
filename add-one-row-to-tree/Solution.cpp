// https://leetcode.com/problems/add-one-row-to-tree

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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        map<TreeNode *, int>level;
        queue<TreeNode*>q;
        q.push(root);
        level[root]=1;
        while(!q.empty()){
            TreeNode *r=q.front();
            q.pop();
            if(r->left){
                q.push(r->left);
                level[r->left]=level[r]+1;
            }
            if(r->right){
                q.push(r->right);
                level[r->right]=level[r]+1;
            }
        }
        
        if(d==1){
            TreeNode *nn=new TreeNode(v);
            nn->left=root;
            root=nn;
        }
        
        else {

            for(auto it=level.begin();it!=level.end();it++){
                if(it->second==d-1){
                    TreeNode *t=it->first;
                    TreeNode *nn=new TreeNode(v);
                    TreeNode *tmp=t->left;
                    t->left=nn;
                    nn->left=tmp;
                    nn=new TreeNode(v);
                    tmp=t->right;
                    t->right=nn;
                    nn->right=tmp;
                }
            }
        }
        
        return root;
    }
};