// https://leetcode.com/problems/search-in-rotated-sorted-array

class Solution {
public:
    void solve(vector<int>&nums, int low, int high, int key, int &found){
        if((high-low) <= 2){
            int a=(low<nums.size())?nums[low]:numeric_limits<int>::min();
            int b=(low+1 < nums.size())?nums[low+1]:numeric_limits<int>::min();
            int c=(low+2 < nums.size())?nums[low+2]:numeric_limits<int>::min();
            if(a==key)
                found=low;
            else if(b==key)
                found=low+1;
            else if(c==key)
                found=low+2;
            return;
        }
        
        int mid=low+(high-low)/2;
        
        if(nums[mid]==key){
            found=mid;
            return;
        }
        
        if(nums[low]<=nums[mid]){
            if(nums[mid]<=nums[high]){
                if(nums[mid]>key){
                    solve(nums, low, mid-1, key, found);
                }
                else if(nums[mid]<key){
                    solve(nums, mid+1, high, key, found);
                }
            }
            else {
                if(nums[low]<=key && nums[mid]>key){
                    solve(nums, low, mid-1, key, found);
                }
                else 
                    solve(nums, mid+1, high, key, found);
            }
        }
        else {
            if(nums[mid]>=nums[high]){
                if(nums[mid]>key){
                    solve(nums, mid+1, high, key, found);
                }
                else if(nums[mid]<key) {
                    solve(nums, low, mid-1, key, found);
                }
            }
            else {
                if(nums[mid]<key && nums[high]>=key){
                    solve(nums, mid+1, high, key, found);
                }
                else
                    solve(nums, low, mid-1, key, found);
            }
        }
        
    }
    
    int search(vector<int>& nums, int target) {
        int found=-1;
        solve(nums, 0, nums.size()-1, target, found);
        return found;
    }
};