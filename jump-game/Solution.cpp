// https://leetcode.com/problems/jump-game

class Solution {
public:

    bool canJump(vector<int>& nums) {
        vector<bool>dp(nums.size(), 0);
        dp[0]=1;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(j+nums[j]>=i && dp[j]){
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp[nums.size()-1];
    }
};