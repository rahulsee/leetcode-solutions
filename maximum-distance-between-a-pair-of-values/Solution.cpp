// https://leetcode.com/problems/maximum-distance-between-a-pair-of-values

class Solution {
public:
    
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i=nums1.size()-1;
        int j=nums2.size()-1;
        int maxdist=0;
        while(i>=0 && j>=0){
            if(nums1[i]<=nums2[j]){
                maxdist=max(maxdist, (j-i));
                i--;
            }
            else {
                j--;
            }
        }
        return maxdist;
    }
};