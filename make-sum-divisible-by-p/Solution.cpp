// https://leetcode.com/problems/make-sum-divisible-by-p

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
            nums[i]=nums[i]%p;
        for(int n:nums){
            sum=(sum+n)%p;
        }
        int target=sum%p;
        if(target==0){
            return 0;
        }
        vector<int>psum(nums.begin(), nums.end());
        for(int i=1;i<psum.size();i++){
            psum[i]+=psum[i-1];
            psum[i]%=p;
        }
        unordered_map<int,int>m;
        int ans=psum.size();
        m[0]=0;
        for(int i=0;i<psum.size();i++){
            int diff=(psum[i]-target+p)%p;
            if(m.find(diff)!=m.end()){
                ans=min(ans, i-m[diff]+1);
            }
            m[psum[i]]=i+1;
        }
        return ans==psum.size()?-1:ans;
    }
};