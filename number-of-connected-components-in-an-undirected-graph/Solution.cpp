// https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph

class Solution {
public:
    
    bool visited[2001];
    
    void dfs(vector<int>g[], int v, int n){
        visited[v]=true;
        for(int c: g[v]){
            if(!visited[c])
                dfs(g,c,n);
        }
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int>g[n+1];
        for(int i=0;i<edges.size();i++){
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(g,i,n);
                cnt++;
            }
        }
        return cnt;
    }
};