// https://leetcode.com/problems/cut-off-trees-for-golf-event

struct tree{
    int x,y,h;
    tree(int x,int y,int h)
    {
        this->x=x;
        this->y=y;
        this->h=h;
    }
};
struct sorter{
    bool operator()(tree a, tree b)
    {
        return a.h < b.h;
    }
};

class Solution {
public:
    
    bool limit(long long x,long long y,long long m,long long n)
    {
        return (x>=0 && x<m && y>=0 && y<n);
    }
    
    
    long long compute_sp(vector<vector<int > >&forest,long long a,long long b,long long c,long long d)
    {
        long long m=forest.size();
        long long n=forest[0].size();
        queue<pair<long long,long long> >q;
        q.push(make_pair(a,b));
        bool visited[forest.size()][forest[0].size()];
        long long steps[forest.size()][forest[0].size()];
        memset(visited,0,sizeof(visited));
        memset(steps,0,sizeof(steps));
        while(!q.empty())
        {
            pair<long long,long long> v;
            v=q.front();
            q.pop();
            if(v.first==c && v.second==d)
            {
                return steps[c][d];
            }
            if(limit(v.first-1,v.second,m,n))
            {
                long long x=v.first-1;
                long long y=v.second;
                if(!visited[x][y] && forest[x][y]!=0)
                {
                    steps[x][y]=steps[v.first][v.second]+1;
                    visited[x][y]=1;
                    q.push(make_pair(x,y));
                }
            }
            if(limit(v.first+1,v.second,m,n))
            {
                long long x=v.first+1;
                long long y=v.second;
                if(!visited[x][y] && forest[x][y]!=0)
                {
                    steps[x][y]=steps[v.first][v.second]+1;
                    visited[x][y]=1;
                    q.push(make_pair(x,y));
                }
            }
            if(limit(v.first,v.second-1,m,n))
            {
                long long x=v.first;
                long long y=v.second-1;
                if(!visited[x][y] && forest[x][y]!=0)
                {
                    steps[x][y]=steps[v.first][v.second]+1;
                    visited[x][y]=1;
                    q.push(make_pair(x,y));
                }
            }
            if(limit(v.first,v.second+1,m,n))
            {
                long long x=v.first;
                long long y=v.second+1;
                if(!visited[x][y] && forest[x][y]!=0)
                {
                    steps[x][y]=steps[v.first][v.second]+1;
                    visited[x][y]=1;
                    q.push(make_pair(x,y));
                }
            }
        }
        return -1;
    }
    
    long long cutOffTree(vector<vector<int>>& forest) {
        
        int m=forest.size();
        int n=forest[0].size();
        int total=0;
        vector<tree>t;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                t.push_back(tree(i,j,forest[i][j]));
        }
        sort(t.begin(),t.end(),sorter());
        int sx=0;
        int sy=0;
        for(int i=0;i<t.size();i++)
        {
            if(t[i].h>1)
            {
                int temp=compute_sp(forest,sx,sy,t[i].x,t[i].y);
                if(temp==-1)
                    return -1;
                total+=temp;
                sx=t[i].x;
                sy=t[i].y;
            }
        }
        return total;
    }
};