// https://leetcode.com/problems/minimum-operations-to-make-array-equal

class Solution {
public:
    int minOperations(int n) {
        long long last=2*n-1;
        long long first=(n%2)?n+2:n+1;
        long long numElems=n/2;
        long long sum=(numElems*(first+last))/2;
        long long sub=numElems*n;
        return sum-sub;
    }
};