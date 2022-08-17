// https://leetcode.com/problems/random-point-in-non-overlapping-rectangles

class Solution {
public:
    
    int a,b,x,y;
    int offa;
    int offb;
    int ridx;
    vector<vector<int>>rects;
    int total=0;
    vector<int>arr;
    
    Solution(vector<vector<int>>& rects) {
        this->rects=rects;
        for(vector<int>r: rects)
        {
            int area=(r[2]-r[0]+1)*(r[3]-r[1]+1);
            arr.push_back(area);
            total+=area;
        }
        for(int i=1;i<arr.size();i++)
            arr[i]+=arr[i-1];
    }
    
    vector<int> pick() {
        
        int point_idx=rand()%total;
        
        int ridx=upper_bound(arr.begin(), arr.end(), point_idx)-arr.begin();
        
        a=rects[ridx][0];
        b=rects[ridx][1];
        x=rects[ridx][2];
        x=x-a;
        y=rects[ridx][3];
        y=y-b;
        offa=a;
        offb=b;
        a=0;
        b=0;
        int len=(x+1)*(y+1);
        int idx=rand()%len;
        int xx=idx%(x+1);
        int yy=idx/(x+1);
        vector<int>ans;
        ans.push_back(xx+offa);
        ans.push_back(yy+offb);
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */