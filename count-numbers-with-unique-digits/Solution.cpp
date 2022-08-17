// https://leetcode.com/problems/count-numbers-with-unique-digits

class Solution {
public:
    
    int n;
    
    int csb(int mask){
        int cnt=0;
        while(mask>0){
            mask=mask & (mask-1);
            cnt++;
        }
        return cnt;
    }
    
    int solve(int mask, int n){
        if(csb(mask)==n){
            return 1;
        }
        int start=(mask==0)?1:0;
        int ans=0;
        for(int i=start;i<=9;i++){
            if(mask & (1<<i))
                continue;
            ans+=solve(mask | (1<<i), n);
        }
        return ans;
    }
    
    int countNumbersWithUniqueDigits(int n) {
       int ans=0;
       for(int i=0;i<=n;i++){
          ans+=solve(0,i);
       }
       return ans; 
    }
};