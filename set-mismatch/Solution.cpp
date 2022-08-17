// https://leetcode.com/problems/set-mismatch

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>tmp;
        int ac=0;
        sort(nums.begin(), nums.end());
        int cur=nums[0];
        ac=(nums.size()*(nums.size()+1))/2;
        for(int i=1;i<nums.size();i++){
            if((nums[i]^nums[i-1])==0){
                tmp.push_back(nums[i]);
            }
            else {
                cur+=nums[i];
            }
        }
        // cout<<ac<<"  "<<cur<<endl;
        tmp.push_back(abs(ac-cur));
        return tmp;
    }
};