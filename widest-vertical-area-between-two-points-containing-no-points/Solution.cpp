// https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        
        auto cmp= [](vector<int>a, vector<int>b)
        {
            return a[0]<b[0];
        };
        
        sort(points.begin(), points.end(), cmp);
        int n=points.size();
        
        int maxi=0;
        
        for(int i=1;i<points.size();i++)
        {
            maxi=max(points[i][0]-points[i-1][0], maxi);
        }
        
        return maxi;
        
    }
};