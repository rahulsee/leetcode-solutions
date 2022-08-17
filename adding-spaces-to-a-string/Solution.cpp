// https://leetcode.com/problems/adding-spaces-to-a-string

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int i=0;
        int j=0;
        int n=s.length();
        int m=spaces.size();
        string ans;
        while(i<n)
        {
            if(j<m && spaces[j]==i)
            {
                ans.push_back(' ');
                j++;
            }
            ans.push_back(s[i]);
            i++;
        }
        while(j<m)
        {
            ans.push_back(' ');
            j++;
        }
        return ans;
    }
};