// https://leetcode.com/problems/split-linked-list-in-parts

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    int compute_len(ListNode *root)
    {
        int count=0;
        while(root!=NULL)
        {
            root=root->next;
            count++;
        }
        return count;
    }
    
    void add_node(vector<ListNode*>&splits,vector<ListNode*>&heads,int i,ListNode *r)
    {
        if(splits[i]==NULL)
        {
            splits[i]=new ListNode;
            splits[i]->val=r->val;
            splits[i]->next=NULL;
            heads[i]=splits[i];
        }
        else
        {
            splits[i]->next=new ListNode(r->val);
            splits[i]=splits[i]->next;
        }
    }    
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int len=compute_len(root);
        int partlen=len/k;
        ListNode *r=root;
        vector<ListNode*>splits(k,NULL);
        vector<ListNode*>heads(k,NULL);
        
        if(partlen==0)
        {
            for(int i=0;i<len;i++)
            {
                add_node(splits,heads,i,r);
                r=r->next;
            }
            return heads;
        }
        else
        {
            int count=0;
            for(int i=0;i<k;i++)
            {
                for(int j=0;j<partlen;j++)
                {
                    add_node(splits,heads,i,r);
                    r=r->next;
                }
                if(count < len%k){
                    add_node(splits,heads,i,r);
                    r=r->next;
                    count++;
                }
            }
            
        }
        return heads;
    }
    
};