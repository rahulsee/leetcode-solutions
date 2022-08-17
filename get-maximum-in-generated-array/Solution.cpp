// https://leetcode.com/problems/get-maximum-in-generated-array

class Solution {
public:
    unordered_map<int,int>f;
    int ans=0;
    int solve(int n){
        if(n==0 || n==1)
        {
            ans=max(ans, n);
            return n;
        }
        if(f.find(n)!=f.end())
            return f[n];
        if(n%2==0){
            f[n]=solve(n/2);
        }
        else {
            f[n]=solve(n/2)+solve(n/2+1);
        }
        ans=max(ans, f[n]);
        return f[n];
    }
    int getMaximumGenerated(int n) {
        for(int i=0;i<=n;i++)
            solve(i);
        return ans;
    }
};