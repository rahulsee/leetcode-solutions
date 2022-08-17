// https://leetcode.com/problems/network-delay-time

class Solution {
public:
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>>>g(n+1);
        for(int i=0;i<times.size();i++)
        {
            g[times[i][0]].push_back(make_pair(times[i][1], times[i][2]));
        }
        
        vector<bool>done(n+1, false);
        vector<int>dist(n+1, numeric_limits<int>::max());
        dist[k]=0;
        dist[0]=0;
        for(int i=0;i<n;i++)
        {
            int v=-1;
            int mindist=numeric_limits<int>::max();
            for(int j=1;j<=n;j++)
            {
                if(!done[j] && dist[j]<mindist)
                {
                    v=j;
                    mindist=dist[j];
                }
            }
            
            if(v==-1)
            {
                return -1;
            }
            
            done[v]=true;
            
            for(pair<int,int>p: g[v])
            {
                int j=p.first;
                int w=p.second;
                dist[j]=min(dist[v]+w, dist[j]);
            }
            
        }
        
        return *max_element(dist.begin()+1, dist.end());
        
    }
};