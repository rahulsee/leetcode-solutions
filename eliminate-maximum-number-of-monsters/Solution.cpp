// https://leetcode.com/problems/eliminate-maximum-number-of-monsters

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<double>arr;
        for(int i=0;i<dist.size();i++)
        {
            double ts=(double)dist[i]/(double)speed[i];
            arr.push_back(ts);
        }
        sort(arr.begin(), arr.end());
        int ans=1;
        for(int i=1;i<arr.size();i++){
            if((double)i>=arr[i])
                return ans;
            ans++;
        }
        return ans;
    }
};