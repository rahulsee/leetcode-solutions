// https://leetcode.com/problems/is-graph-bipartite

class Solution {
public:
    
    bool bfs(vector<vector<int>>& graph, vector<int>&colors, int src){
        queue<int>q;
        q.push(src);
        colors[src]=0;
        while(!q.empty()){
            int v=q.front();
            q.pop();
            for(int i=0;i<graph[v].size();i++){
                if(colors[graph[v][i]]==-1){
                    q.push(graph[v][i]);
                    colors[graph[v][i]]=1-colors[v];
                }
                else if(colors[graph[v][i]]==colors[v])
                    return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>colors(graph.size(), -1);
        for(int i=0;i<colors.size();i++){
            if(colors[i]==-1){
                if(!bfs(graph, colors, i))
                    return false;
            }
        }
        return true;
    }
};