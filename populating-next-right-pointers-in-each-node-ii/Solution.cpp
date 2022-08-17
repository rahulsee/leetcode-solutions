// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return root;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            vector<Node*>vec;
            while(!q.empty()){
                Node *n=q.front();
                q.pop();
                if(n->left)
                    vec.push_back(n->left);
                if(n->right)
                    vec.push_back(n->right);
            }
            int s=vec.size();
            for(int i=0;i<s-1;i++){
                vec[i]->next=vec[i+1];
            }
            for(int i=0;i<s;i++){
                q.push(vec[i]);
            }
        }
        return root;
    }
};