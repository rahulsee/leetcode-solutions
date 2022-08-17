// https://leetcode.com/problems/trapping-rain-water

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==0){
            return 0;
        }
        vector<int>area(height.size(), 0);
        int maxi=height[0];
        int maxIndex=0;
        for(int i=1;i<height.size()-1;i++){
            area[i]=max(maxi-height[i], 0);
            if(maxi < height[i]){
                maxIndex=i;
                maxi=height[i];
            }
        }
        maxi=height[height.size()-1];
        maxIndex=height.size()-1;
        int sum=0;
        for(int i=height.size()-2;i>0;i--){
            area[i]=min(area[i], max(maxi-height[i], 0));
            if(maxi < height[i]){
                maxIndex=i;
                maxi=height[i];
            }
            sum+=area[i];
        }
        return sum;
    }
};