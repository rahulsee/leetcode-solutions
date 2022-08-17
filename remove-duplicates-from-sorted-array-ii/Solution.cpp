// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=2)
            return nums.size();
        int cur=1;
        for(int i=2;i<nums.size();i++){
            if(nums[i]==nums[cur] && nums[i]==nums[cur-1])
                continue;
            else {
                cur++;
                nums[cur]=nums[i];
            }
        }
        return cur+1;
    }
};