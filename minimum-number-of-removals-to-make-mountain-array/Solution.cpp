// https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        
        int N=nums.size();
        
        vector<int>dpleft(nums.size(), 1);

        for(int i=1;i<N;i++){
            for(int j=0;j<i;j++){
                if(nums[j] < nums[i]){
                    dpleft[i]=max(dpleft[i], dpleft[j]+1);
                }
            }
        }
        
        vector<int>dpright(nums.size(), 1);
        
        for(int i=N-2;i>=0;i--){
            for(int j=N-1;j>i;j--){
                if(nums[j] < nums[i]){
                    dpright[i]=max(dpright[i], dpright[j]+1);
                }
            }
        }
        
        int maxi=0;
        
        for(int i=1;i<N-1;i++){
            maxi=max(maxi, dpleft[i]+dpright[i]-1);
        }
        
        return N-maxi;
    }
};