// https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans=0;
        long long cnt=1;
        long long prev=prices[0];
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i] == prev-1)
            {
                cnt++;
            }
            else
            {
                long long x=(cnt*(cnt+1))>>1;
                ans+=x;
                cnt=1;
            }
            prev=prices[i];
        }
        long long x=(cnt*(cnt+1))>>1;
        ans+=x;
        return ans;
    }
};