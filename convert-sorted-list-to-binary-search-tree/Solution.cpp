// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree

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
    
    TreeNode* solve(vector<ListNode*>arr, int low, int high){
        if(low>high)
            return NULL;
        if(low==high){
            TreeNode *node=new TreeNode(arr[low]->val);
            node->left=node->right=NULL;
            return node;
        }
        int mid=(low+high+1)/2;
        TreeNode *tn=new TreeNode(arr[mid]->val);
        tn->left=tn->right=NULL;
        tn->left=solve(arr, low, mid-1);
        tn->right=solve(arr, mid+1, high);
        return tn;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        vector<ListNode*>arr;
        while(head!=NULL){
            arr.push_back(head);
            head=head->next;
        }
        return solve(arr, 0, arr.size()-1);
    }
};