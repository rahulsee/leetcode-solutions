// https://leetcode.com/problems/missing-number-in-arithmetic-progression

class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int mini=arr[0];
        int maxi=arr[0];
        int sum=0;
        for(int num: arr){
            mini=min(mini, num);
            maxi=max(maxi, num);
            sum+=num;
        }
        int n=arr.size();
        int tot=((n+1)*(maxi+mini))/2;
        return tot-sum;
    }
};