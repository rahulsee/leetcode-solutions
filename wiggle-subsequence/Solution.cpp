// https://leetcode.com/problems/wiggle-subsequence

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int maxPos=0;
        int maxNeg=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                maxPos=maxNeg+1;
            }
            else if(nums[i]<nums[i-1]){
                maxNeg=maxPos+1;
            }
        }
        return max(maxNeg, maxPos)+1;
    }
};