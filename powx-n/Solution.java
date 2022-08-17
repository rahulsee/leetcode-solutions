// https://leetcode.com/problems/powx-n

class Solution {
    
    public double solve(double x,int n){
        if(n==0)
            return 1;
        if(n%2==0)
        {
            double ans=solve(x,n/2);
            return ans*ans;
        }
        else{
            double ans=solve(x,n/2);
            return ans*ans*x;
        }
    }
    
    public double myPow(double x, int n) {
        double res;
        if(n < 0)
        {
            res=(1/solve(x,-n));
            return res;
        }
        else
            return solve(x,n);
    }
}