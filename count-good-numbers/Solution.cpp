// https://leetcode.com/problems/count-good-numbers

class Solution {
public:
    
    int MOD=1000000007;
    
    long long power(long long x, long long y)
    {
        if(y==0)
            return 1;
        long long temp=power(x, y/2);
        if(y%2)
            return (((temp%MOD) * (temp%MOD))%MOD * (x%MOD))%MOD;
        return ((temp%MOD) * (temp%MOD))%MOD;
    }
    
    int countGoodNumbers(long long n) {
        if(n==1)
            return 5;
        long long ans=power((long long)20, n/2);
        if(n%2)
            return (ans*5)%MOD;
        return ans%MOD;
    }
};