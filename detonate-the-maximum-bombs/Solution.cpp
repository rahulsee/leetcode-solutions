// https://leetcode.com/problems/detonate-the-maximum-bombs

class Solution {
public:
    
    void topsort(vector<int>g[], int cur, int n, stack<int>&st, bool visited[])
    {
        if(visited[cur])
            return;
        visited[cur]=true;
        for(int c: g[cur])
        {
            topsort(g,c,n, st, visited);
        }
        st.push(cur);
    }
    
    void dfs(vector<int>g[], int cur, int n, int &cnt, bool visited[])
    {
        if(visited[cur])
            return;
        visited[cur]=true;
        for(int c: g[cur])
        {
            dfs(g,c,n,cnt,visited);
        }
        cnt++;
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<int>g[n];
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                long long r1=(long long)bombs[i][2]*bombs[i][2];
                long long r2=(long long)bombs[j][2]*bombs[j][2];
                long long dx=(long long)bombs[i][0]-bombs[j][0];
                long long dy=(long long)bombs[i][1]-bombs[j][1];
                long long dist=dx*dx + dy*dy;
                if(dist <= r1)
                {
                    g[i].push_back(j);
                }
                if(dist <= r2)
                {
                    g[j].push_back(i);
                }
            }
        }
        stack<int>st;
        bool visited[n];
        memset(visited, 0, sizeof(visited));
        for(int i=0;i<n;i++)
        {
            topsort(g, i, n, st, visited);
        }
        memset(visited, 0, sizeof(visited));
        int maxi=0;
        while(!st.empty())
        {
            int cnt=0;
            dfs(g, st.top(), n, cnt, visited);
            memset(visited, 0, sizeof(visited));
            maxi=max(cnt, maxi);
            st.pop();
        }
        return maxi;
    }
};