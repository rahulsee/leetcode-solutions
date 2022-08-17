// https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int,int>>arr;
        for(int i=0;i<=n;i++) {
            arr.push_back(make_pair(max(0, i-ranges[i]),  min(n, i+ranges[i])));
        }
        sort(arr.begin(), arr.end(), [](pair<int,int>&a, pair<int,int>&b)
             {
                if(a.first==b.first)
                {
                    return a.second > b.second;
                }
                return a.first < b.first;
             });
    
        int cnt=1;
        int cap=arr[0].second;
        int max_end=cap;
        int i=1;
        while(cap < n)
        {
            while(i<=n && arr[i].first <= cap)
            {
                max_end=max(max_end, arr[i].second);           
                i++;
            }
            if(max_end <= cap)
                return -1;
            cap=max_end;
            cnt++;
            if(cap==n && cnt<=n)
                return cnt;
        }
        return cnt;
    }
};