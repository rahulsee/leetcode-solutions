// https://leetcode.com/problems/maximum-xor-for-each-query

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
       int n=nums.size();
       vector<int>ans(n); 
       int j=n-1;
       int mask=(1<<maximumBit)-1;
       for(int i=1;i<nums.size();i++){
           nums[i]^=nums[i-1];
       }
       for(int i=0;i<nums.size();i++){
           ans[j]= ~nums[i];
           j--;
       }
       for(int i=0;i<n;i++){
           ans[i]=ans[i] & mask;
       } 
        return ans;
    }
};