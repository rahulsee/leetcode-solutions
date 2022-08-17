// https://leetcode.com/problems/3sum-closest

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans=100001;
        int diff=numeric_limits<int>::max();
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            int l=i+1;
            int r=n-1;
            while(l<r){
                if(nums[i]+nums[l]+nums[r] < target) {
                    int tmp=abs(nums[i]+nums[l]+nums[r]-target);
                    if(diff > tmp){
                        diff=tmp;
                        ans=nums[i]+nums[l]+nums[r];
                    }
                    l++;
                }
                else {
                    int tmp=abs(nums[i]+nums[l]+nums[r]-target);
                    if(diff > tmp){
                        diff=tmp;
                        ans=nums[i]+nums[l]+nums[r];
                    }
                    r--;
                }
            }
        }
        return ans;
    }
};