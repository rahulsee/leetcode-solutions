// https://leetcode.com/problems/distinct-subsequences-ii

class Solution {
public:
    int distinctSubseqII(string S) {
         long long mod=1000000007;
        vector<long long>dp(S.length()+1);
        dp[0]=1;
        unordered_map<char, long long>last_seen;
        for( long long i=1;i<=S.length();i++)
        {
            int repeat=0;
            if(last_seen.find(S[i-1])!=last_seen.end()){
                repeat=dp[last_seen[S[i-1]]]%mod;
            } 
            dp[i]=((2*dp[i-1])%mod-(repeat)%mod)%mod;
            last_seen[S[i-1]]=i-1; 
        }
       return (dp[S.length()]-1+mod)%mod;
    }
};