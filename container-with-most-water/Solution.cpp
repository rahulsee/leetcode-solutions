// https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int area=0;
        while(l<r){
            if(height[l] > height[r]){
                area=max(area, height[r]*(r-l));
                r--;
            }
            else {
                area=max(area, height[l]*(r-l));
                l++;
            }
        }
        return area;
    }
};