// https://leetcode.com/problems/interval-list-intersections

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& fl, vector<vector<int>>& sl) {
        int p=0;
        int q=0;
        vector<vector<int> >ans;
        while(p<fl.size() && q<sl.size()){
            vector<int>isect;
            isect.push_back(max(fl[p][0], sl[q][0]));
            isect.push_back(min(fl[p][1], sl[q][1]));
            if(isect[0]<=isect[1]){
                ans.push_back(isect);
            }
            if(fl[p][1]<sl[q][1]){
                p++;
            }
            else {
                q++;
            }
        }
        return ans;
    }
};