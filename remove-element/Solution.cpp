// https://leetcode.com/problems/remove-element

class Solution {
public:
    
    int partition(vector<int>&arr, int val){
        int i=-1;
        int j=0;
        int r=arr.size()-1;
        while(j<=r-1){
            if(arr[j]>val){
                i++;
                swap(arr[i], arr[j]);
            }
            j++;
        }
        swap(arr[i+1], arr[r]);
        return i+1;
    }
    
    int removeElement(vector<int>& nums, int val) {
        if(nums.size()==0){
            return 0;
        }
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==val){
                swap(nums[i], nums[nums.size()-1]);
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==val){
                count++;
                nums[i]=0;
            }
        }
        partition(nums, 0);
        return nums.size()-count;
    }
};