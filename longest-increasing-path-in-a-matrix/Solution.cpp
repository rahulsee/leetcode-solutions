// https://leetcode.com/problems/longest-increasing-path-in-a-matrix

class Solution {
public:
    
    bool visited[207][207];
    int dp[207][207];
    
    bool reach(vector<vector<int>>& matrix, int i, int j){
        return i>=0 && i<matrix.size() && j>=0 && j<matrix[0].size();
    }
    
    int solve(vector<vector<int>>& matrix, int i, int j, int prev){
         if(dp[i][j])
            return dp[i][j];
        visited[i][j]=true;
        if(reach(matrix,i-1,j) && !visited[i-1][j] && matrix[i-1][j]>prev){
            dp[i][j]=max(dp[i][j],1+solve(matrix, i-1,j,matrix[i-1][j]));
        }
        if(reach(matrix,i+1,j) && !visited[i+1][j] && matrix[i+1][j]>prev){
            dp[i][j]=max(dp[i][j],1+solve(matrix, i+1,j,matrix[i+1][j]));
        }
        if(reach(matrix,i,j-1) && !visited[i][j-1] && matrix[i][j-1]>prev){
            dp[i][j]=max(dp[i][j],1+solve(matrix, i,j-1,matrix[i][j-1]));
        }
        if(reach(matrix,i,j+1) && !visited[i][j+1] && matrix[i][j+1]>prev){
            dp[i][j]=max(dp[i][j],1+solve(matrix, i,j+1,matrix[i][j+1]));
        }
        visited[i][j]=false;
        return dp[i][j];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(visited, 0, sizeof(visited));
        memset(dp, 0, sizeof(visited));
        int ans=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(dp[i][j]==0){
                    solve(matrix, i,j, matrix[i][j]);
                }
                ans=max(ans, dp[i][j]);
            }
        }
        return ans+1;
    }
};