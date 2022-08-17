// https://leetcode.com/problems/number-of-distinct-islands

class Solution {
public:
    
    int r,c;
    
    void dfs(vector<vector<int>>& grid, int si, int sj, int i, int j, vector<pair<int,int> >&vec, vector<vector<bool> >&visited){
        if(i>=r || i<0 || j>=c || j<0)
            return;
        if(grid[i][j]==0)
            return;
        if(visited[i][j])
            return;
        visited[i][j]=true;
        vec.push_back({si-i,sj-j});
        dfs(grid,si, sj, i-1,j, vec, visited);
        dfs(grid,si, sj, i+1,j, vec, visited);
        dfs(grid,si, sj, i,j-1, vec, visited);
        dfs(grid,si, sj, i,j+1, vec, visited);
    }
    
    int numDistinctIslands(vector<vector<int>>& grid) {
        vector<vector<bool> >visited;
        r=grid.size();
        c=grid[0].size();
        for(int i=0;i<r;i++){
            vector<bool>tmp(c, false);
            visited.push_back(tmp);
        }
        set<vector<pair<int,int> > >cset;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    vector<pair<int,int> >vec;
                    dfs(grid, i, j ,i, j, vec, visited);
                    cset.insert(vec);
                }
            }
        }
        return cset.size();
    }
};