// https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<pair<int,int> >g;
        for(int i=0;i<groupSizes.size();i++){
            g.push_back({groupSizes[i], i});
        }
        sort(g.begin(), g.end());
        int n=g.size();
        vector<vector<int>>ans;
        for(int i=0;i<n;){
            vector<int>tmp;
            int j=i;
            while(j<i+g[i].first){
                tmp.push_back(g[j].second);
                j++;
            }
            i=j;
            ans.push_back(tmp);
        }
        return ans;
    }
};