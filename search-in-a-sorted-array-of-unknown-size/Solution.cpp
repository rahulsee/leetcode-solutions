// https://leetcode.com/problems/search-in-a-sorted-array-of-unknown-size

/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int high=1;
        int low=0;
        while(reader.get(high)<=target){
            high*=2;
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            cout<<low<<" "<<high<<endl;
            if(reader.get(mid)>target){
                high=mid-1;
            }
            else if(reader.get(mid)==target){
                return mid;
            }
            else {
                low=mid+1;
            }
        }
        return -1;
    }
};