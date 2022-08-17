// https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges

class Solution {
public:
    unordered_map<int, int>dp;
    int minDays(int n) {
        if(n==0 || n==1)
            return n;
        if(dp.find(n)!=dp.end()){
            return dp[n];
        }
        dp[n]=min(minDays(n/2)+n%2+1, minDays(n/3)+n%3+1);
        return dp[n];
    }
};