// https://leetcode.com/problems/subarray-sums-divisible-by-k

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int,int>pmap;
        int sum=0;
        for(int i=0;i<A.size();i++){
            sum=(sum+A[i]+30000*K)%K;
            pmap[sum]++;
        }
        int ans=0;
        for(auto it=pmap.begin();it!=pmap.end();it++){
            if(it->first==0){
                ans=ans+(it->second*(it->second+1))/2;
            }
            else {
                ans=ans+(it->second*(it->second-1))/2;
            }
        }
        return ans;
    }
};