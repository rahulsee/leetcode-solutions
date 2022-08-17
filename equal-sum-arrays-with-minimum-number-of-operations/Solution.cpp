// https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations

class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int sum1=0;
        int sum2=0;
        for(int n: nums1)
            sum1+=n;
        for(int n: nums2)
            sum2+=n;
        if(sum1==sum2)
            return 0;
        if(sum1<sum2){
            swap(sum1, sum2);
            swap(nums1,nums2);
        }
        int x=nums1.size()-1;
        int y=0;
        if(nums1.size()*1 > nums2.size()*6){
            return -1;
        }
        int step=0;
        while(x>=0 || y<nums2.size()){
            if(sum1<=sum2)
                return step;
            int d1=-1;
            int d2=-1;
            if(x>=0)
                d1=nums1[x]-1;
            if(y<nums2.size())
                d2=6-nums2[y];
            if(d1>=d2){
                sum1-=d1;
                x--;
            }
            else {
                sum2+=d2;
                y++;
            }
            step++;
        }
        if(sum1<=sum2)
            return step;
        return -1;
    }
};