// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix

class Solution {
public:
    struct node {
        int val;
        int index;
        node(){
            index=-1;
            val=0;
        }
    };
    struct compare {
        bool operator()(node a, node b){
            if(a.val == b.val)
                return a.index < b.index;
            return a.val<b.val;
        }
    };
    
    bool lesser(node a, node b){
        if(a.val == b.val)
            return a.index > b.index;
        return a.val > b.val;
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<node>oc(mat.size());
        for(int i=0;i<mat.size();i++){
            oc[i].index=i;
        }
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                oc[i].val+=mat[i][j];
            }
        }
        priority_queue<node, vector<node>, compare>pq;
        for(int i=0;i<k;i++){
            pq.push(oc[i]);
        }
        for(int i=k;i<oc.size();i++){
            node top=pq.top();
            if(lesser(top, oc[i])){
                pq.pop();
                pq.push(oc[i]);
            }
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().index);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};