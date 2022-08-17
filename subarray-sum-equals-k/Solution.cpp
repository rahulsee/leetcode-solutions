// https://leetcode.com/problems/subarray-sum-equals-k

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0;
        unordered_map<int, int>s;
        s[0]=1;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            if(s.find(sum-k)!=s.end()){
                cnt+=s[sum-k];
            }
            s[sum]++;
        }
        return cnt;
    }
};