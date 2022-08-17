// https://leetcode.com/problems/4sum-ii

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int N=A.size();
        unordered_map<int, int>um;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                um[A[i]+B[j]]++;
            }
        }
        int ans=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(um.find(-C[i]-D[j])!=um.end()){
                    ans+=um[-C[i]-D[j]];
                }
            }
        }
        return ans;
    }
};