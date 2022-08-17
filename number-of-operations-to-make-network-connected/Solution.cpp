// https://leetcode.com/problems/number-of-operations-to-make-network-connected

struct DisjointSet {
    int *rank;
    int *parent;
    int n;
    DisjointSet(int n)
    {
        rank=new int[n];
        parent=new int[n];
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            rank[i]=1;
        }
        this->n=n;
    }
    
    bool _union(int x, int y)
    {
        int px=_find(x);
        int py=_find(y);
        if(px==py)
        {
            return false;
        }
        if(rank[px] >= rank[py])
        {
            parent[py]=px;
            rank[px]++;
        }
        else
        {
            parent[px]=py;
            rank[py]++;
        }
        return true;
    }
    
    int num_connected_comp()
    {
        unordered_set<int>s;
        int cc=0;
        for(int i=0;i<n;i++)
        {
            int num=parent[i];
            cout<<num<<endl;
            if(s.find(num)==s.end())
            {
                s.insert(num);
                cc++;
            }
        }
        return cc;
    }
    
    int _find(int x)
    {
        if(x==parent[x])
            return x;
        parent[x]=_find(parent[x]);
        return parent[x];
    }
    
    int connected_comp()
    {
        unordered_set<int>s;
        for(int i=0;i<n;i++)
        {
            parent[i]=_find(parent[i]);
            s.insert(parent[i]);
        }
        return s.size();
    }
    
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        DisjointSet ds(n);
        int needed=0;
        for(vector<int>c: connections)
        {
            if(ds._union(c[0], c[1]))
                needed++;
        }
        int avail=connections.size()-needed;
        int nc=ds.connected_comp();
        if(avail>=(nc-1))
            return nc-1;
        else
            return -1;
    }
};