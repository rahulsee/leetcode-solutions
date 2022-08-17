// https://leetcode.com/problems/meeting-rooms-ii

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        unordered_map<int,int>rooms;
        for(vector<int>a: intervals)
        {
            rooms[a[0]]++;
            rooms[a[1]]--;
        }
        int maxi=0;
        vector<pair<int,int>>arr(rooms.begin(), rooms.end());
        sort(arr.begin(), arr.end());
        maxi=arr[0].second;
        for(int i=1;i<arr.size();i++)
        {
            arr[i].second+=arr[i-1].second;
            maxi=max(arr[i].second, maxi);
        }
        return maxi;
    }
};