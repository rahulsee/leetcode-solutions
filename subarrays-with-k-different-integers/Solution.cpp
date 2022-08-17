// https://leetcode.com/problems/subarrays-with-k-different-integers

class Solution {
public:
    
    int solve(vector<int>A, int K){
        unordered_map<int,int>um;
        int i=0;
        int ans=0;
        int j=0;
        int n=A.size();
        for(int i=0;i<n;i++){
            um[A[i]]++;
            while(j<i && um.size()>K){
                um[A[j]]--;
                if(um[A[j]]==0)
                    um.erase(A[j]);
                j++;
            }
            if(um.size()<=K)
            ans+=(i-j+1);
        }
        return ans;
    }
    
    
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return solve(A,K)-solve(A, K-1);
    }
};