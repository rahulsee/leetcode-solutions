// https://leetcode.com/problems/fixed-point

class Solution {
public:
    int fixedPoint(vector<int>& arr) {
        int low=0;
        int high=arr.size()-1;
        int ans=numeric_limits<int>::max();
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]>mid){
                high=mid-1;
            }
            else if(arr[mid]<mid){
                low=mid+1;
            }
            else {
                ans=min(ans, mid);
                high=mid-1;
            }
        }
        return ans==numeric_limits<int>::max()?-1 : ans;
    }
};