// https://leetcode.com/problems/squares-of-a-sorted-array

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int min_index=0;
        int mini=abs(nums[0]);
        for(int i=0;i<nums.size();i++){
            if(abs(nums[i])<mini){
                mini=abs(nums[i]);
                min_index=i;
            }
        }
        int i=min_index;
        int j=min_index+1;
        int n=nums.size();
        vector<int>ans;
        while(i>=0 && j<n){
            int x=nums[i]*nums[i];
            int y=nums[j]*nums[j];
            if(x<y){
                ans.push_back(x);
                i--;
            }
            else {
                ans.push_back(y);
                j++;
            }
        }
        while(i>=0){
            int x=nums[i]*nums[i];
            ans.push_back(x);
            i--;
        }
        while(j<n){
            int y=nums[j]*nums[j];
            ans.push_back(y);
            j++;
        }
        return ans;
    }
};