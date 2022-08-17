// https://leetcode.com/problems/max-area-of-island

class Solution {
public:
    
    int m,n;
    vector<vector<bool>>visited;
    
    bool limit(int i, int j){
        return i>=0 && i<m && j>=0 && j<n;
    }
    
    void dfs(int i, int j, vector<vector<int>>& grid, int &ans) {
        ans++;
        visited[i][j]=1;
        if(limit(i+1,j) && !visited[i+1][j] && grid[i+1][j]==1){
            visited[i+1][j]=true;
            dfs(i+1, j, grid, ans);
        }
        
        if(limit(i-1,j) && !visited[i-1][j] && grid[i-1][j]==1) {
            visited[i-1][j]=true;
            dfs(i-1, j, grid, ans);
        }
        
        if(limit(i, j-1) && !visited[i][j-1] && grid[i][j-1]==1) {
            visited[i][j-1]=true;
            dfs(i, j-1, grid, ans);
        }
        
        if(limit(i, j+1) && !visited[i][j+1] && grid[i][j+1]==1) {
            visited[i][j+1]=true;
            dfs(i, j+1, grid, ans);
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int ans=0;
        int maxi=0;
        visited=vector<vector<bool> >(m, vector<bool>(n, false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j]==1){
                    int ans=0;
                    dfs(i,j, grid, ans);
                    maxi=max(ans, maxi);
                }
            }
        }
        return maxi;
    }
};