// https://leetcode.com/problems/beautiful-arrangement

class Solution {
public:
    
    void solve(vector<bool> &visited, vector<int>&cur, int n, int &res){
        if(cur.size()==n){
            res++;
            return;
        }
        for(int i=1;i<=n;i++){
            if(visited[i])
                continue;
            if(i%(cur.size()+1)==0 || (cur.size()+1)%i==0)
            {
                cur.push_back(i);
                visited[i]=true;
                solve(visited, cur, n, res);
                visited[i]=false;
                cur.pop_back();
            }
        }
    }
    
    int countArrangement(int n) {
        vector<bool>visited(n+1, false);
        vector<int>cur;
        int res=0;
        solve(visited, cur, n, res);
        return res;
    }
};