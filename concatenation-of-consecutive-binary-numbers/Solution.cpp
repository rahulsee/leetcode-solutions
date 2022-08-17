// https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers

class Solution {
public:
    int MOD=1000000007;
    int findlen(int num){
        int cnt=0;
        while(num>0){
            cnt++;
            num=num>>1;
        }
        return cnt;
    }

    
    int concatenatedBinary(int n) {
        int len[n+1];
        int cnt=0;
        int MOD=1000000007;
        len[0]=0;
        len[n]=0;
        for(int i=n-1;i>=1;i--){
            len[i]=findlen(i+1);
        }
        
        long long ans=n;
        long long y=1;
        for(int i=n-1;i>=0;i--){
            long long x=i%MOD;
            long long y=(y*(1<<len[i]))%MOD;
            long long tmp=(x*y)%MOD;
            ans=(ans+tmp+MOD)%MOD;
        }
        return ans;
    }
};