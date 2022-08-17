// https://leetcode.com/problems/peak-index-in-a-mountain-array

class Solution {
public:
    
    int bs(vector<int>arr, int low, int high){
        if(high==low){
            return low;
        }
        if(high-low==1){
            if(arr[high]>arr[low]){
                return high;
            }
            return low;
        }
        int mid=low+(high-low)/2;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
            return mid;
        }
        if(arr[mid]<arr[mid-1]){
            return bs(arr, low, mid-1);
        }
        else 
            return bs(arr, mid+1, high);
    }
    
    int peakIndexInMountainArray(vector<int>& arr) {
        return bs(arr, 0, arr.size()-1);
    }
};