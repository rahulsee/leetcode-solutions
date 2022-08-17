// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,vector<int>>map;
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
            map[nums[i]].push_back(i);
        for(int i=0;i<nums.size();i++)
        {
            if(map.find(target-nums[i])!=map.end() && target!=(2*nums[i])){
                ans.push_back(map[target-nums[i]][0]);
                ans.push_back(map[nums[i]][0]);
                return ans;
            }
            
            else if(2*nums[i]==target && map[nums[i]].size()>=2){
                ans.push_back(map[nums[i]][0]);
                ans.push_back(map[nums[i]][1]);
                return ans;
            }
        }
        return ans;
    }
};