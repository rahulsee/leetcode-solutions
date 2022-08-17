// https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle

class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            int radius=queries[i][2];
            int x1=queries[i][0];
            int y1=queries[i][1];
            int cnt=0;
            for(int j=0;j<points.size();j++){
                int x2=points[j][0];
                int y2=points[j][1];
                int dist=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
                if(dist <= (radius * radius)){
                    cnt++;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};