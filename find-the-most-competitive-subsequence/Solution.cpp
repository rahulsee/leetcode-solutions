// https://leetcode.com/problems/find-the-most-competitive-subsequence

class Solution {
public:
    
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        deque<int>q;
        int n=nums.size();
        for(int i=0;i<n;i++){
            while(!q.empty() && nums[i]<q.back()){
                if(q.size()+n-i <= k)
                    break;
                q.pop_back();
            }
            q.push_back(nums[i]);
        }
        vector<int>ans;
        while(!q.empty() && ans.size()<k){
            ans.push_back(q.front());
            q.pop_front();
        }
        return ans;
    }
};