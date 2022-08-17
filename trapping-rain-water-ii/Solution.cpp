// https://leetcode.com/problems/trapping-rain-water-ii

struct node {
    int x;
    int y;
    int h;
    node(int xx, int yy, int hh){
        x=xx;
        y=yy;
        h=hh;
    }
    node(){
        
    }
};
struct compare{
    bool operator()(node a, node b){
        return a.h > b.h;
    }
};
class Solution {
public:
    
    void pushBoundaryElems(vector<vector<int>>& heightMap, priority_queue<node, vector<node>, compare>&pq, vector<vector<bool> >&visited){
        int r=heightMap.size();
        int c=heightMap[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(i==0 || i==(r-1) || j==0 || j==(c-1)){
                    pq.push(node(i,j,heightMap[i][j]));
                    visited[i][j]=true;
                }
            }
        }
    }
    
    int trapRainWater(vector<vector<int>>& heightMap) {
        priority_queue<node, vector<node>, compare>pq;
        int maxi=0;
        int r=heightMap.size();
        int c=heightMap[0].size();
        vector<vector<bool> >visited(r);
        for(int i=0;i<r;i++){
            vector<bool>tmp(c, false);
            visited[i]=tmp;
        }
        pushBoundaryElems(heightMap,pq, visited);
        int ans=0;
        while(!pq.empty()){
            node n=pq.top();
            pq.pop();
            
            int ox[]={0,0,1,-1};
            int oy[]={1,-1,0,0};
            for(int i=0;i<4;i++){
                int xx=n.x+ox[i];
                int yy=n.y+oy[i];
                if(xx>=0 && xx<r && yy>=0 && yy<c && !visited[xx][yy]){
                    int hh=heightMap[xx][yy];
                    pq.push(node(xx,yy,hh));
                    visited[xx][yy]=true;
                }
            }
            // cout<<maxi<<" "<<n.h<<endl;
            ans+=max(maxi-n.h, 0); 
            maxi=max(maxi, n.h);
        }
        return ans;
    }
};