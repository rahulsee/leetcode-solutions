// https://leetcode.com/problems/fibonacci-number

class Solution {
public:
    
    unordered_map<int,int>dp;
    
    int fib(int n) {
        
        if(n==0) 
            return 0;
        if(n==1)
            return 1;
        
        if(dp.find(n)!=dp.end()){
            return dp[n];
        }
        
        if(n%2==0){
            int k=n/2;
            dp[n]= (2*fib(k-1)+fib(k))*fib(k);
        }
        else {
            int k=(n+1)/2;
            dp[n]= fib(k-1)*fib(k-1)+fib(k)*fib(k);
        }
        return dp[n];
    }
};