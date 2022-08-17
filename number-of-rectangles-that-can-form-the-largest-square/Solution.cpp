// https://leetcode.com/problems/number-of-rectangles-that-can-form-the-largest-square

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int maxi=min(rectangles[0][0], rectangles[0][1]);
        for(int i=1;i<rectangles.size();i++){
            maxi=max(maxi, min(rectangles[i][0], rectangles[i][1]));
        }
        int cnt=0;
        for(int i=0;i<rectangles.size();i++){
            if(maxi==min(rectangles[i][0],rectangles[i][1])){
                cnt++;   
            }
        }
        return cnt;
    }
};