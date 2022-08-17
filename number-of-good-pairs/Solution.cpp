// https://leetcode.com/problems/number-of-good-pairs

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector<int>count(101,0);
        for(int i=0;i<nums.size();i++)
            count[nums[i]]++;
        int ans=0;
        for(int i=0;i<=100;i++)
            ans=ans+(count[i]*(count[i]-1))/2;
        return ans;
    }
};