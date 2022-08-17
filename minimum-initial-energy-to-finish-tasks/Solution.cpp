// https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {

        sort(tasks.begin(), tasks.end(), [](vector<int>&a, vector<int>&b)
             {
                 if(a[1]-a[0]==b[1]-b[0])
                     return a[0] < b[0];
                 return (a[1]-a[0]) > (b[1]-b[0]);
             });
        int ie=0;
        for(vector<int> t: tasks)
            ie+=t[0];
        int ans=ie;
        for(vector<int>t: tasks)
        {
            if(ie>=t[1])
            {
                ie-=t[0];
            }
            else
            {
                ans+=(t[1]-ie);
                ie=t[1];
                ie-=t[0];
            }
        }
        return ans;
    }
};