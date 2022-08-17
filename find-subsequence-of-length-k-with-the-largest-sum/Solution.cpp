// https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
        for(int i=0;i<k;i++)
        {
            pq.push(make_pair(nums[i],i));
        }
        for(int i=k;i<nums.size();i++)
        {
            int top=pq.top().first;
            if(top < nums[i])
            {
                pq.pop();
                pq.push(make_pair(nums[i],i));
            }
        }
        vector<pair<int,int> >ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        auto func = [](pair<int,int>a, pair<int,int>b)
        {
            return a.second < b.second;
        };
        sort(ans.begin(), ans.end(), func);
        vector<int>final_ans;
        for(pair<int,int>p: ans){
            final_ans.push_back(p.first);
        }
        return final_ans;
    }
};