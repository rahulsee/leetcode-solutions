// https://leetcode.com/problems/calculate-money-in-leetcode-bank

class Solution {
public:
    int totalMoney(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            int row=(ceil((double)i/(double)7));
            int col=(i-1)%7;
            ans+=(row+col);
        }
        return ans;
    }
};