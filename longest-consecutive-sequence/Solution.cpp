// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>us(nums.begin(), nums.end());
        int maxi=0;
        for(int num: nums){
            if(us.find(num-1)!=us.end()){
                continue;
                // it will be part of another streak
            }
            else {
                int cnt=0;
                int val=num;
                while(us.find(val)!=us.end()){
                    val++;
                    cnt++;
                }
                maxi=max(maxi, cnt);
            }
        }
        return maxi;
    }
};