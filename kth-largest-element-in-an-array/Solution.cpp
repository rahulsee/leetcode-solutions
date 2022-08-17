// https://leetcode.com/problems/kth-largest-element-in-an-array

class Solution {
public:
    
    int partition(vector<int>&arr, int low, int high){
        int i=low-1;
        int j=low;
        while(j<high){
            if(arr[j]<=arr[high]){
                i++;
                swap(arr[i], arr[j]);
            }
            j++;
        }
        swap(arr[i+1], arr[high]);
        return i+1;
    }
    
    void kthos(vector<int>&nums, int low, int high, int k, int &ans) {
        
        if(low>high)
            return;
        
        if(low == high){
            if(low==k-1){
                ans=nums[low];
            }
            return;
        }
        int q=partition(nums, low, high);
        int p=q-low+1;
        if(p==k) {
            ans=nums[q];
            return;
        }
        else if(p>k){
            kthos(nums, low, q-1, k, ans);
        }
        else {
            kthos(nums, q, high, k-p+1, ans);
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int ans=0;
        kthos(nums, 0, nums.size()-1, nums.size()-k+1, ans);
        return ans;
    }
};