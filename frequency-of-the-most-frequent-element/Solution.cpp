// https://leetcode.com/problems/frequency-of-the-most-frequent-element

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        long long left=0;
        long long sum=0;
        long long ans=0;
        sort(nums.begin(), nums.end());
        for(int right=0;right<nums.size();right++){
            sum+=nums[right];
            while(nums[right]*(right-left+1)-sum>k && left<nums.size()){
                sum-=nums[left];
                left++;
            }
            ans=max(ans, right-left+1);
        }
        return ans;
    }
};