// https://leetcode.com/problems/house-robber

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()<=2)
        {
            return *max_element(nums.begin(), nums.end());
        }
        int x=nums[0];
        int y=nums[1];
        for(int i=2;i<nums.size();i++)
        {
            int maxi=max(x+nums[i], y);
            x=max(x,y);
            y=maxi;
        }
        return max(x,y);
    }
};