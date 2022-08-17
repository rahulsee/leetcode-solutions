// https://leetcode.com/problems/next-permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i;
        for(i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1])
            {
                break;
            }
        }
        int next=numeric_limits<int>::max();
        int nextIndex=-1;
        if(i>=0){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]<nums[j]){
                    if(nums[j]<next){
                        nextIndex=j;
                        next=nums[j];
                    }
                }
            }
            if(nextIndex>=0 && i>=0){
                swap(nums[i], nums[nextIndex]);
            }
        }
        sort(nums.begin()+i+1, nums.end());
    }
};