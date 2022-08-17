// https://leetcode.com/problems/reconstruct-itinerary

class Solution {
public:
       
    void dfs(map<string,priority_queue<string,vector<string>,greater<string> > >&graph,string cur,vector<string>&ans){
        
        while(graph.find(cur)!=graph.end() && !graph[cur].empty()){
            string temp=graph[cur].top();
            graph[cur].pop();
            dfs(graph,temp,ans);
        }
        ans.push_back(cur);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string,priority_queue<string,vector<string>,greater<string> > >graph;
        for(int i=0;i<tickets.size();i++)
            graph[tickets[i][0]].push(tickets[i][1]);
        string start="JFK";
        vector<string>ans;
        // ans.push_back(start);
        dfs(graph,"JFK",ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};