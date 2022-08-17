// https://leetcode.com/problems/redundant-connection

class Solution {
public:
    
    struct DisjointSet 
    {
        int rank[1001];
        int parent[1001];
        DisjointSet()
        {
            for(int i=0;i<=1000;i++)
                rank[i]=0, parent[i]=i;
        }
        
        int find(int p)
        {
            if(p==parent[p])
                return p;
            parent[p]=find(parent[p]);
            return parent[p];
        }
        
        bool unionFind(int a, int b)
        {
            int pa=find(a);
            int pb=find(b);
            if(pa==pb)
                return false;
            if(rank[pa]>rank[pb])
            {
                parent[pb]=pa;
                rank[pa]++;
            }
            else 
            {
                parent[pa]=pb;
                rank[pb]++;
            }
            return true;
        }
    };
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DisjointSet ds;
        vector<int>ans(2);
        for(int i=0;i<edges.size();i++){
            if(!ds.unionFind(edges[i][0], edges[i][1]))
            {
                ans[0]=edges[i][0];
                ans[1]=edges[i][1];
            }
        }
        return ans;
    }
};