// https://leetcode.com/problems/alphabet-board-path

class Solution {
public:
    
    bool limit(int x,int y)
    {
        if(x==5)
            return y==0;
        return x>=0 && x<5 && y>=0 && y<5;
    }
    
    string bfs(int &sx,int &sy,char t)
    {
        map<char,string>path;
        string board[]={
            "abcde",
            "fghij",
            "klmno",
            "pqrst",
            "uvwxy",
            "z    ",
        };
        queue<pair<int,int> >q;
        set<pair<int,int> >visited;
        q.push({sx,sy});
        visited.insert({sx,sy});
        path[board[sx][sy]]="";
        while(!q.empty())
        {
            pair<int,int>p=q.front();
            q.pop();
            int ex,ey;
            sx=p.first;
            sy=p.second;
            //cout<<board[sx][sy]<<endl;
            if(board[sx][sy]==t){
                return path[board[sx][sy]]+"!";
            }
            
            ex=sx-1;
            ey=sy;
            if(visited.find({ex,ey})==visited.end() && limit(ex,ey))
            {
                visited.insert({ex,ey});
                q.push({ex,ey});
                path[board[ex][ey]]=path[board[sx][sy]]+'U';
            }
            
            ex=sx+1;
            ey=sy;
            if(visited.find({ex,ey})==visited.end() && limit(ex,ey))
            {
                visited.insert({ex,ey});
                q.push({ex,ey});
                path[board[ex][ey]]=path[board[sx][sy]]+'D';
            }
            
            
            ex=sx;
            ey=sy-1;
            if(visited.find({ex,ey})==visited.end() && limit(ex,ey))
            {
                visited.insert({ex,ey});
                q.push({ex,ey});
                path[board[ex][ey]]=path[board[sx][sy]]+'L';
            }
            
            
            ex=sx;
            ey=sy+1;
            if(visited.find({ex,ey})==visited.end() && limit(ex,ey))
            {
                visited.insert({ex,ey});
                q.push({ex,ey});
                path[board[ex][ey]]=path[board[sx][sy]]+'R';
            }
            
        }
        return ".";
        
        
    }
    
    string alphabetBoardPath(string target) {
        int cur=0;
        int sx=0;
        int sy=0;
        string path="";
        for(int i=0;i<target.length();i++)
            path+=bfs(sx,sy,target[i]);
        return path;
    }
};