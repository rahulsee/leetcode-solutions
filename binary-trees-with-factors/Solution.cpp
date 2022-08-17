// https://leetcode.com/problems/binary-trees-with-factors

class Solution {
public:
    
    int MOD=1000000007;
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        vector<long>dp(arr.size(), 1);
        sort(arr.begin(), arr.end());
        unordered_map<int, int>index;
        for(int i=0;i<arr.size();i++){
            index[arr[i]]=i;
        }
        for(int i=1;i<arr.size();i++){
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0){
                    int arr_k=arr[i]/arr[j];
                    if(index.find(arr_k)!=index.end()){
                        dp[i]=(dp[i]+((dp[j]%MOD)*(dp[index[arr_k]]%MOD)%MOD))%MOD;
                    }
                }
            }
        }
        int sum=0;
        for(int i=0;i<dp.size();i++){
            sum+=dp[i];
            sum%=MOD;
        }
        return sum;
    }
    
};