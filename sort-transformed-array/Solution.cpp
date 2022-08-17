// https://leetcode.com/problems/sort-transformed-array

class Solution {
public:
    
    int func(int x,int a,int b,int c){
        return a*x*x+b*x+c;
    }
    
    bool decreasing(vector<int>arr){
        int n=arr.size();
        for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1])
                return true;
        }
        return false;
    }
    
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=func(nums[i], a,b,c);
        }
        if(nums.size()<=2){
            sort(nums.begin(), nums.end());
            return nums;
        }
        int max_index=0;
        int min_index=0;
        int maxi=nums[0];
        int mini=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]>maxi){
                maxi=nums[i];
                max_index=i;
            }
            else if(nums[i]<mini){
                mini=nums[i];
                min_index=i;
            }
        }
        if(a>=0){
            int i=min_index;
            int j=min_index+1;
            vector<int>ans;
            while(i>=0 && j<n){
                if(nums[i]<nums[j]){
                    ans.push_back(nums[i]);
                    i--;
                }
                else {
                    ans.push_back(nums[j]);
                    j++;
                }
            }
            
            while(i>=0){
                ans.push_back(nums[i]);
                i--;
            }
            while(j<n){
                ans.push_back(nums[j]);
                j++;
            }
            return ans;
        }
        else {
            int i=0;
            int j=n-1;
            vector<int>ans;
            while(i<=j){
                if(nums[i]<nums[j]){
                    ans.push_back(nums[i]);
                    i++;
                }
                else {
                    ans.push_back(nums[j]);
                    j--;
                }
            }
            return ans;
        }
    }
};