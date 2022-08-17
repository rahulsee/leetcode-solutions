// https://leetcode.com/problems/product-of-array-except-self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>left(n+2);
        vector<int>right(n+2);
        left[0]=left[n+1]=1;
        for(int i=1;i<=n;i++){
            left[i]=left[i-1]*nums[i-1];
        }
        right[0]=right[n+1]=1;
        for(int i=n;i>=1;i--){
            right[i]=right[i+1]*nums[i-1];
        }
        vector<int>ans;
        for(int i=1;i<=n;i++){
            ans.push_back(left[i-1]*right[i+1]);
        }
        return ans;
    }
};