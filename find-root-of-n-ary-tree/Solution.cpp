// https://leetcode.com/problems/find-root-of-n-ary-tree

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    Node* findRoot(vector<Node*> tree) {
        unordered_map<Node*, Node*>parent;
        for(int i=0;i<tree.size();i++){
            Node *p=tree[i];
            for(Node *c: p->children){
                parent[c]=p;
            }
        }
        for(int i=0;i<tree.size();i++){
            if(parent.find(tree[i])==parent.end())
                return tree[i];
        }
        return NULL;
    }
};