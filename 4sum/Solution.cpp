// https://leetcode.com/problems/4sum

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        int n=nums.size();
        for(int i=0;i<n-3;i++){
            if(i!=0 && nums[i]==nums[i-1]){
                continue;
            }
            for(int j=i+1;j<n-2;j++){
                if(j!=(i+1) && nums[j]==nums[j-1])
                    continue;
                int l=j+1;
                int r=n-1;
                while(l<r){
                    if(nums[i]+nums[j]+nums[l]+nums[r] > target){
                        r--;
                    }
                    else if(nums[i]+nums[j]+nums[l]+nums[r] < target){
                        l++;
                    }
                    else {
                        vector<int>tmp;
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[j]);
                        tmp.push_back(nums[l]);
                        tmp.push_back(nums[r]);
                        ans.push_back(tmp);
                        int x=nums[l];
                        int y=nums[r];
                        while(l<r && x==nums[l] && y==nums[r]){
                            l++;
                            r--;
                        }
                    }
                }
            }
        }
        return ans;
    }
};