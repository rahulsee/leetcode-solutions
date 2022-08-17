// https://leetcode.com/problems/patching-array

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long max_pos=1;
        long long cnt=0;
        for(long long num: nums) {
            if(max_pos>=num){
                max_pos+=num;
                continue;
            }
            else {
                while(max_pos<num && max_pos<=n){
                    cnt++;
                    max_pos=2*max_pos;
                }
                max_pos+=num;
            }
        }
        
        
        while(max_pos<n){
            max_pos=2*max_pos;
            cnt++;
        }
        
        return cnt;
    }
};