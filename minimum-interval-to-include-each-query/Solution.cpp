// https://leetcode.com/problems/minimum-interval-to-include-each-query

class Solution {
public:
    
    struct compare 
    {
        bool operator()(pair<int,int>a, pair<int,int>b)
        {
            if(a.first==b.first)
                return a.second > b.second;
            return a.first > b.first;
        }
    };
    
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        vector<int>temp=queries;
        sort(queries.begin(), queries.end());
        priority_queue<pair<int,int>, vector<pair<int,int> >, compare>pq;
        unordered_map<int,int>ans;
        int i=0;
        for(int j=0;j<queries.size();j++)
        {
            while(i<intervals.size() && intervals[i][0] <= queries[j])
            {
                pq.push(make_pair(intervals[i][1]-intervals[i][0]+1, intervals[i][1]));
                i++;
            }
            while(!pq.empty() && pq.top().second < queries[j])
                pq.pop();
            if(!pq.empty())
                ans[queries[j]]=pq.top().first;
        }
        vector<int>arr;
        for(int num: temp){
            if(ans.find(num)!=ans.end())
            arr.push_back(ans[num]);
            else
            arr.push_back(-1);
        }
        return arr;
    }
};