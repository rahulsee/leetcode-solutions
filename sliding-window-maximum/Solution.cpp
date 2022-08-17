// https://leetcode.com/problems/sliding-window-maximum

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>deq;
        vector<int>ans;
        for(int i=0;i<k;i++){
            while(!deq.empty() && nums[i]>=nums[deq.back()])
                deq.pop_back();
            deq.push_back(i);
        }
        ans.push_back(nums[deq.front()]);
        for(int i=k;i<nums.size();i++){
            while(!deq.empty() && deq.front()<=i-k)
                deq.pop_front();
            while(!deq.empty() && nums[i]>=nums[deq.back()])
                deq.pop_back();
            deq.push_back(i);
            ans.push_back(nums[deq.front()]);
        }
        return ans;
    }
};