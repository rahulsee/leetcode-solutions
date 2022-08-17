// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
    public int maxProfit(int[] prices) {
        if(prices.length==0)
            return 0;
        int minvalue=prices[0];
        int maxdiff=0;
        for(int i=1;i<prices.length;i++){
            minvalue=Math.min(minvalue, prices[i]);
            maxdiff=Math.max(prices[i]-minvalue, maxdiff);
        }
        return maxdiff;
    }
}