// https://leetcode.com/problems/power-of-two

class Solution {
public:
    bool isPowerOfTwo(int n) {
        bitset<64>bset(n);
        return bset.count()==1;
    }
};