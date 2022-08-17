// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    
    int firstPos(vector<int>&nums, int target){
        int ans=-1;
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                if(ans==-1)
                    ans=mid;
                else
                    ans=min(ans, mid);
                high=mid-1;
            }
            else if(nums[mid]<target) {
                low=mid+1;
            }
            else {
                high=mid-1;
            }
        }
        return ans;
    }
    
    int lastPos(vector<int>&nums, int target){
        int ans=-1;
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                ans=max(ans, mid);
                low=mid+1;
            }
            else if(nums[mid]<target) {
                low=mid+1;
            }
            else {
                high=mid-1;
            }
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        ans.push_back(firstPos(nums, target));
        ans.push_back(lastPos(nums, target));
        return ans;
    }
};