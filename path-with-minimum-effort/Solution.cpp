// https://leetcode.com/problems/path-with-minimum-effort

class Solution {
public:

    int rows, cols;
    
    bool inrange(int x, int y){
        return x>=0 && x<rows && y>=0 && y<cols;
    }
    
    void dfs(vector<vector<int>>& heights, bool visited[][101], int x, int y, int k, bool &result){
        if(visited[x][y] || result)
            return;
        visited[x][y]=true;
        if(x==heights.size()-1 && y==heights[0].size()-1) {
            result=true;
            return;
        }
        if(inrange(x-1,y) && abs(heights[x-1][y]-heights[x][y])<=k){
            dfs(heights, visited, x-1, y,k, result);
        }
        if(inrange(x+1,y) && abs(heights[x+1][y]-heights[x][y])<=k){
            dfs(heights, visited, x+1, y,k, result);
        }
        if(inrange(x,y+1) && abs(heights[x][y+1]-heights[x][y])<=k){
            dfs(heights, visited, x, y+1,k, result);
        }
        if(inrange(x,y-1) && abs(heights[x][y-1]-heights[x][y])<=k){
            dfs(heights, visited, x, y-1,k, result);
        }
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int low=0;
        int maxi=0;
        rows=heights.size();
        cols=heights[0].size();
        bool visited[101][101];
        memset(visited, 0, sizeof(visited));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                maxi=max(maxi, heights[i][j]);
            }
        }
        int high=maxi;
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            bool result=false;
            dfs(heights, visited, 0,0,mid, result);
            memset(visited, 0, sizeof(visited));
            if(result){
                ans=min(ans, mid);
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return ans;
    }
};