// https://leetcode.com/problems/max-number-of-k-sum-pairs

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int>count;
        for(int n: nums)
            count[n]++;
        int ans=0;
        for(auto it=count.begin();it!=count.end();it++){
            int n=it->first;
            int a=count[n];
            if(n==(k-n))
                ans+=(a/2);
            else if(n<(k-n) && count.find(k-n)!=count.end())
                ans+=min(a,count[k-n]);
        }
        return ans;
    }
};