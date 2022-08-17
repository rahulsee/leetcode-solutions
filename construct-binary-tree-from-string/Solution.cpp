// https://leetcode.com/problems/construct-binary-tree-from-string

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
    
    TreeNode* str2tree(string s) {
        TreeNode *root=NULL;
        stack<TreeNode*>st;
        int i=0;
        while(i<s.length()){
            if(s[i]=='(')
                i++;
            else if(s[i]==')') {
                st.pop();
                i++;
            }
            else {
                string num;
                while(i<s.length() && (s[i]=='-' || (s[i]>='0' && s[i]<='9') )){
                    num.push_back(s[i]);
                    i++;
                }
                int val=stoi(num);
                TreeNode *node=new TreeNode(val);
                if(st.empty()){
                    st.push(node);
                    root=node;
                }
                else {
                    TreeNode *par=st.top();
                    if(!par->left)
                        par->left=node;
                    else
                        par->right=node;
                    st.push(node);
                }
            }
        }
         return root;
    }
};