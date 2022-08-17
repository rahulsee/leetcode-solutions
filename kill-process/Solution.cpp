// https://leetcode.com/problems/kill-process

class Solution {
public:
    
    vector<int>parent;
    vector<int>child;

    void bfs(unordered_map<int, vector<int> >g, unordered_set<int>&s, int kill){
        queue<int>q; 
        q.push(kill);
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            s.insert(cur);
            for(auto it=g[cur].begin();it!=g[cur].end();it++){
                if(s.find(*it)!=s.end())
                    continue;
                q.push(*it);
            }
        }
    }
    
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        parent=ppid;
        child=pid;
        unordered_set<int>s;
        unordered_map<int, vector<int> >g;
        for(int i=0;i<parent.size();i++){
            g[parent[i]].push_back(child[i]);
        }
        bfs(g, s, kill);
        vector<int>ans;
        for(auto it=s.begin();it!=s.end();it++){
            ans.push_back(*it);
        }
        return ans;
    }
};