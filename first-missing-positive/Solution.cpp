// https://leetcode.com/problems/first-missing-positive

class Solution {
public:
    
    void solve(vector<int>&nums, long long low, long long high, long long &ans){
        if(high==low){
            if(find(nums.begin(), nums.end(), low)==nums.end())
            ans=min(ans, low);
            return;
        }
        if(high < low)
            return;
        if(high-low==1){
            if(find(nums.begin(), nums.end(), high)==nums.end())
                ans=min(ans, high);
            if(find(nums.begin(), nums.end(), low)==nums.end())
                ans=min(ans, low);
            return;
        }
        long long mid=low+(high-low)/2;
        if(find(nums.begin(), nums.end(), mid)==nums.end()){
            ans=min(ans, mid);
            solve(nums, low, mid-1, ans);
        }
        else {
            solve(nums, low, mid-1, ans);
            solve(nums, mid+1, high, ans);
        }
    }
    
    int firstMissingPositive(vector<int>& nums) {
        long long low=1;
        long long high=((long long)1<<31)-1;
        long long ans=high;
        solve(nums, 1, (long long)1<<31-1, ans);
        return ans;
    }
};