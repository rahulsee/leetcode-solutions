// https://leetcode.com/problems/all-paths-from-source-lead-to-destination

class Solution {
public:
    
    bool recStack[10001];
    bool visited[10001];
    int src;
    int dest;
    vector<int>graph[10001];
    
    void solve(int v, int &cycleExists, int &reached, int &onlyLeaf)
    {
        visited[v]=true;
        recStack[v]=true;
        if(v==dest)
            reached=1;
        bool flag=false;
        for(int c: graph[v])
        {
            flag=true;
            if(!visited[c])
                solve(c, cycleExists, reached, onlyLeaf);
            if(recStack[c])
                cycleExists=1;
        }
        if(flag==false && v!=dest)
            onlyLeaf=false;
        recStack[v]=false;
    }
    
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        src=source;
        dest=destination;
        for(vector<int>e: edges)
        {
            graph[e[0]].push_back(e[1]);    
        }
        int ce=0;
        int r=0;
        int ol=1;
        solve(src, ce, r, ol);
        if(!ce && r && ol)
            return true;
        return false;
    }
};