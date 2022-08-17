// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long target=0;
        for(int n: nums)
            target+=n;
        target-=x;
        int left=0;
        long long sum=0;
        int len=-1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            while((left<=i) && (sum>target)){
                sum-=nums[left];
                left++;
            }
            if(sum==target)
                len=max(len, i-left+1);
        }
        if(len==-1)
            return len;
        return nums.size()-len;
    }
};