// https://leetcode.com/problems/assign-cookies

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        int i=0;
        int j=0;
        int m=g.size();
        int n=s.size();
        int cnt=0;
        while(i<m && j<n){
            if(g[i]<=s[j]){
                i++;
                j++;
                cnt++;
            }
            else {
                j++;
            }
        }
        return cnt;
    }
};