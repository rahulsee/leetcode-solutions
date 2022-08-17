// https://leetcode.com/problems/search-in-rotated-sorted-array-ii

class Solution {
public:
    
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() -1;
		while(left <= right) {
			if(target == nums[left] || target == nums[right]) return true;
			else if(target > nums[left]) left++;
			else if(target < nums[right]) right--;
			else break;
		}
		return false;
    }
};