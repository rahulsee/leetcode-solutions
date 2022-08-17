// https://leetcode.com/problems/cheapest-flights-within-k-stops

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        long long maxi=numeric_limits<long long>::max();
        vector<long long>dist(n,maxi);
        dist[src]=0;
        for(int i=0;i<=K;i++){
            vector<long long>temp;
            temp=dist;
            for(int i=0;i<flights.size();i++)
            {
                int u=flights[i][0];
                int v=flights[i][1];
                int w=flights[i][2];
                if(dist[u]!=maxi && dist[u]+w < temp[v] )
                {
                    temp[v]=dist[u]+w;
                }
            }
            dist=temp;
        }
        if(dist[dst]!=maxi)
            return dist[dst];
        return -1;
    }
};