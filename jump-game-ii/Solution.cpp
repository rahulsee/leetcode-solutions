// https://leetcode.com/problems/jump-game-ii

class Solution {
public:
    int jump(vector<int>& nums) {
       int jumps=1;
       int curEnd=nums[0];
       int farthest=nums[0];
        
       if(nums.size()==1 || nums[0]==0)
           return 0;
        int n=nums.size();
       for(int i=1;i<n-1;i++){
           farthest=max(farthest, nums[i]+i);
           if(i==curEnd){
               jumps++;
               curEnd=farthest;
           }
       }
        return jumps;
    }
};