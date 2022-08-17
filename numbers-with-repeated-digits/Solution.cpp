// https://leetcode.com/problems/numbers-with-repeated-digits

class Solution {
public:
    
    
    int target;
    unordered_map<int, unordered_map<int,int> >dp;
    int sum=0;
    int solve(int cur, int mask, int num, int lz, int len)
    {
        if(num > target)
            return 0;
        
        if(cur==len){
            return 1;
        }

        int ans=0;
        for(int i=0;i<10;i++)
        {
            if(i==0 && lz==1)
            {
                ans+=solve(cur+1, mask, num*10, lz, len);
            }
            else if(!(mask & (1<<i)))
                ans+=solve(cur+1, mask | (1<<i), num*10+i, lz & (i==0), len);
        }
        return ans;
    }
    
    int numDupDigitsAtMostN(int n) {
        int full_len=to_string(n).size();
        int uniq=0;
        target=n;
        dp.clear();
        sum=solve(0,0,0,1,full_len);    
        return n-sum+1;
    }
};