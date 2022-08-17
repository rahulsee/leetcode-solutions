// https://leetcode.com/problems/find-xor-sum-of-all-pairs-bitwise-and

class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int xor_val=0;
        for(int num: arr2){
            xor_val ^= num;
        }
        int ans=0;
        for(int num: arr1){
            ans=ans ^ (xor_val & num);
        }
        return ans;
    }
};