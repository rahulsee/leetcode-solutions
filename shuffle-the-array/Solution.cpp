// https://leetcode.com/problems/shuffle-the-array

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        for(int i=0;i<n;i++){
            nums[i]=nums[i]|(nums[i+n]<<10);
        }
        int j=n-1;
        for(int i=2*n-1;i>=0;i-=2){
            int tmp=nums[j];
            int mask=(1<<10)-1;
            nums[i]=(tmp & (mask<<10)) >> 10;
            nums[i-1]=tmp & mask;
            j--;
        }
        return nums;
    }
};