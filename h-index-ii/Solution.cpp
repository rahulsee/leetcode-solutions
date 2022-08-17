// https://leetcode.com/problems/h-index-ii

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int low=0;
        int high=citations.size()-1;
        int n=citations.size();
        int ans=0;
        while(low <= high){
            int mid=low+(high-low)/2;
            if(citations[mid] >= n-mid){
                ans=max(ans,n-mid);
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};