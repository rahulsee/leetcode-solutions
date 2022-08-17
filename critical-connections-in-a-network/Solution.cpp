// https://leetcode.com/problems/critical-connections-in-a-network

class Solution {
public:
    int time=0;
    vector<vector<int>>ans;
    void dfs(vector<int>g[], vector<int>&in, vector<int>&low, int cur, int par, vector<bool>&visited){
        visited[cur]=true;
        in[cur]=++time;
        low[cur]=time;
        for(int v: g[cur]){
            if(v==par)
                continue;
            else if(visited[v]){
                // back edge -- can never be bridge
                low[cur]=min(low[cur], in[v]);
            }
            else {
                dfs(g, in, low, v, cur, visited);
                low[cur]=min(low[cur], low[v]);
                if(in[cur] < low[v]){
                    vector<int>arr(2);
                    arr[0]=cur;
                    arr[1]=v;
                    ans.push_back(arr);
                }
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>in(n);
        vector<int>low(n);
        vector<int> g[n];
        vector<bool>visited(n, false);
        int e=connections.size();
        time=0;
        for(int i=0;i<e;i++){
            g[connections[i][0]].push_back(connections[i][1]);
            g[connections[i][1]].push_back(connections[i][0]);
        }
        dfs(g, in, low, 0, -1, visited);
        return ans;
    }
};