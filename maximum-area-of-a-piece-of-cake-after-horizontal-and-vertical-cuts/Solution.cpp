// https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        horizontalCuts.insert(horizontalCuts.begin(),0);
        verticalCuts.insert(verticalCuts.begin(),0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        long long maxH=0, maxW=0;
        for(int i=1;i<horizontalCuts.size();i++){
            maxH=max(maxH, (long long)(horizontalCuts[i]-horizontalCuts[i-1]));
            maxH=maxH%1000000007;
        }
        for(int i=1;i<verticalCuts.size();i++){
            maxW=max(maxW, (long long)(verticalCuts[i]-verticalCuts[i-1]));
            maxW=maxW%1000000007;
        }
        return (maxH*maxW)%1000000007;
    }
};