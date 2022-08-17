// https://leetcode.com/problems/the-time-when-the-network-becomes-idle

class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        unordered_map<int,int>tt;
        queue<int>q;
        q.push(0);
        tt[0]=0;
        vector<vector<int> >g(patience.size());
        for(int i=0;i<edges.size();i++)
        {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        while(!q.empty())
        {
            int f=q.front();
            q.pop();
            for(int c: g[f])
            {
                if(tt.find(c)==tt.end())
                {
                    tt[c]=tt[f]+1;
                    q.push(c);
                }
            }
        }
        for(auto &[k,v]: tt)
            tt[k]=v*2;
        
        vector<int>last(patience.size());
        for(int i=0;i<patience.size();i++)
        {
            if(patience[i]==0)
                continue;
            if((tt[i] % patience[i]) == 0)
            {
                last[i]=max(0,(tt[i]/patience[i]-1)*patience[i]);
            }
            else 
            {
                last[i]=(tt[i]/patience[i])*patience[i];
            }
        }
        
        int ans=0;
        for(int i=0;i<patience.size();i++)
        {
            ans=max(ans, last[i]+tt[i]+1);
        }
        return ans;
    }
};