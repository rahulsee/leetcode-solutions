// https://leetcode.com/problems/unique-binary-search-trees

class Solution {
public:
    int numTrees(int n) {
        if(n<=2){
        if(n==0 || n==1)
            return 1;
        return 2;
    }
    long long dp[n+1];
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++){
        dp[i]=0;
        for(int j=0;j<i;j++){
            dp[i]+=((dp[j]*dp[i-1-j]));
        }
    }
	return dp[n];
    }
};