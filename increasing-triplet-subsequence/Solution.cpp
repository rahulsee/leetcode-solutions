// https://leetcode.com/problems/increasing-triplet-subsequence

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        set<int>jset;
        set<int>kset;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(jset.upper_bound(nums[i])!=jset.end())
            {
                return true;
            }
            
            else if(kset.upper_bound(nums[i])!=kset.end())
            {
                jset.insert(nums[i]);
            }
            
            else 
            {
                kset.insert(nums[i]);
            }
            
        }
        return false;
    }
};