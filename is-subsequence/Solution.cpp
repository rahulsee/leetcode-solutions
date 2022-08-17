// https://leetcode.com/problems/is-subsequence

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int start=0;
        for(int i=0;i<s.length();i++)
        {
            int index=t.find(s[i],start);
            if(index==string::npos)
                return false;
            start=index+1;
        }
        return true;
        
    }
};