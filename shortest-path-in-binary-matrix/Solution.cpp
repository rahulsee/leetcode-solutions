// https://leetcode.com/problems/shortest-path-in-binary-matrix

class Solution {
public:
    int row;
    int col;
    
    bool valid(int x, int y){
        return x>=0 && x<row && y>=0 && y<col;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,int> >q;
        row=grid.size();
        col=grid[0].size();
        int dx[]={0, 0, 1, 1, 1, -1, -1, -1};
        int dy[]={1, -1, 0, -1, 1, 1, 0, -1};
        if(grid[0][0]!=0 || grid[row-1][col-1]!=0)
            return -1;
        q.push({0,0});
        int mat[row][col];
        bool visited[row][col];
        memset(mat, 0, sizeof(mat));
        memset(visited, 0, sizeof(visited));
        mat[0][0]=1;
        visited[0][0]=1;
        while(!q.empty()){
            pair<int,int>p=q.front();
            if(p.first==(row-1) && p.second==(col-1))
                return mat[row-1][col-1];
            q.pop();
            for(int i=0;i<8;i++){
                int x=p.first+dx[i];
                int y=p.second+dy[i];
                if(valid(x,y) && !visited[x][y] && grid[x][y]==0){
                    visited[x][y]=1;
                    q.push({x,y});
                    mat[x][y]=mat[p.first][p.second]+1;
                }
            }
        }
        return -1;
    }
};