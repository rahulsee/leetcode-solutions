// https://leetcode.com/problems/xor-queries-of-a-subarray

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int x[arr.size()+1];
        int n=arr.size();
        x[0]=0;
        for(int i=1;i<=n;i++)
        {
            x[i]=arr[i-1];
            x[i]^=x[i-1];
        }
        vector<int>ans;
        for(int i=0;i<queries.size();i++)
        {
            int left=queries[i][0]+1;
            int right=queries[i][1]+1;
            int a=x[right];
            int b=x[left-1];
            ans.push_back(a^b);
        }
        return ans;
    }
};