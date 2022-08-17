// https://leetcode.com/problems/jump-game-iii

class Solution {
public:
    
    void DFS(unordered_map<int, vector<int> >graph, int start, vector<bool>&visited, vector<int>arr){
        if(visited[start])
            return;
        visited[start]=true;
        if(arr[start]==0)
            return;
        if(graph[start].size()>0 && !visited[graph[start][0]])
            DFS(graph, graph[start][0], visited, arr);
        if(graph[start].size()>1 && !visited[graph[start][1]])
            DFS(graph, graph[start][1], visited, arr);
    }
    
    bool canReach(vector<int>& arr, int start) {
        unordered_map<int, vector<int> >graph;
        for(int i=0;i<arr.size();i++){
            int left=i-arr[i];
            int right=i+arr[i];
            if(left >= 0)
                graph[i].push_back(left);
            if(right < arr.size())
                graph[i].push_back(right);
        }
        vector<bool>visited(arr.size(), false);
        DFS(graph, start, visited, arr);
        for(int i=0;i<arr.size();i++){
            if(visited[i] && !arr[i])
                return true;
        }
        return false;
    }
};