// https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        priority_queue<int>pq;
        int sum=0;
        for(int n:nums){
            sum+=n;
            pq.push(n);
        }
        int ans=0;
        vector<int>vec;
        while(!pq.empty()){
            int num=pq.top();
            vec.push_back(num);
            pq.pop();
            ans+=num;
            sum-=num;
            if(ans > sum){
                return vec;
            }
        }
        return vec;
    }
};