// https://leetcode.com/problems/search-insert-position

class Solution {
public:
    
    int myupperbound(vector<int>&nums,int target)
    {
        int low=0;
        int high=nums.size()-1;
        int ans=numeric_limits<int>::max();
        while(low <= high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid] > target)
            {
                ans=min(mid,ans);
                high=mid-1;
            }
            else if(nums[mid] < target)
            {
                
                low=mid+1;
            }
            else
                return mid;
                
        }
        return ans;
        
    }
    
    int searchInsert(vector<int>& nums, int target) {
        if(target<nums[0])
            return 0;
        if(target > nums[nums.size()-1])
            return nums.size();
        int index=myupperbound(nums,target);
        return index;
    }
};