// https://leetcode.com/problems/non-decreasing-array

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt=0;
        vector<int>a=nums;
        vector<int>b=nums;
        for(int i=1;i<a.size();i++){
            if(a[i]<a[i-1]){
                a[i]=a[i-1];
                cnt++;
            }
        }
        int cnt2=0;
        for(int i=b.size()-2;i>=0;i--){
            if(b[i]>b[i+1]){
                b[i]=b[i+1];
                cnt2++;
            }
        }
        int ans=min(cnt,cnt2);
        return ans<=1;
    }
};