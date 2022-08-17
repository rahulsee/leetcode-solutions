// https://leetcode.com/problems/single-number-ii

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int>bits(32,0);
        for(int i=0;i<nums.size();i++)
        {
            int n=nums[i];
            for(int j=0;j<32;j++){
                //cout<<(n & 1)<<endl;
                bits[j]+=(n & 1);
                n = n>>1;
            }
        }
        for(int i=0;i<32;i++)
            bits[i]%=3;
        int num=0;
        for(int j=0;j<32;j++)
        {
            num|=(bits[j]<<j);
        }
        return num;
        
    }
};