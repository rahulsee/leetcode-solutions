// https://leetcode.com/problems/copy-list-with-random-pointer

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*>m1, m2;
        Node *newhead=NULL;
        Node *newtail=NULL;
        Node *r=head;
        while(r!=NULL){
            Node *node=new Node(r->val);
            if(newhead==NULL){
                newhead=node;
                newtail=node;
            }
            else {
                newtail->next=node;
                newtail=newtail->next;
            }
            m1[node]=r;
            m2[r]=node;
            r=r->next;
        }
        r=newhead;
        while(r!=NULL){
            r->random=m2[m1[r]->random];
            r=r->next;
        }
        return newhead;
    }
};