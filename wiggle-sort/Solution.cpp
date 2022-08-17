// https://leetcode.com/problems/wiggle-sort

class Solution {
public:
    void wiggleSort(vector<int>& a) {
        bool rise=false;
        bool fall=true;
        for(int i=1;i<a.size();i++)
        {
            rise=!rise;
            fall=!fall;
            if(a[i]>=a[i-1] && rise)
                continue;
            if(a[i]<=a[i-1] && fall)
                continue;
            swap(a[i], a[i-1]);
        }
    }
};