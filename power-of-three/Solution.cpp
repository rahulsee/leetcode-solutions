// https://leetcode.com/problems/power-of-three

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0)
            return false;
        long long ans=pow(3,19);
        return ans%n==0;
    }
};