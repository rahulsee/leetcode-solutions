// https://leetcode.com/problems/word-search

class Solution {
public:
    
    int rows, cols;
    int visited[6][6];
    
    bool exist(vector<vector<char>>& board, string word) {
        rows=board.size();
        cols=board[0].size();
        memset(visited, 0, sizeof(visited));
        bool done=false;
        
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(board[i][j] != word[0])
                    continue;
                solve(board, i,j,word, 0, done);
                if(done)
                    return done;
            }
        }
        
        return done;
    }
    
    bool inrange(int i, int j)
    {
        return i>=0 && i<rows && j>=0 && j<cols;
    }
    
    void solve(vector<vector<char>>&board, int i, int j, string word, int cur, bool &done)
    {
        if(cur == word.length() || done)
        {
            done=true;
            return;
        }
        
        if(!inrange(i,j))
            return;
        
        if(board[i][j] != word[cur])
            return;
        
        if(visited[i][j])
            return;
        
        visited[i][j]=true;
        
        // cout<<i<<" "<<j<<" "<<cur<<endl;
        
        solve(board, i-1, j, word, cur+1, done);
        solve(board, i+1, j, word, cur+1, done);
        solve(board, i, j-1, word, cur+1, done);
        solve(board, i, j+1, word, cur+1, done);
        
        visited[i][j]=false;
        
        
    }
    
};