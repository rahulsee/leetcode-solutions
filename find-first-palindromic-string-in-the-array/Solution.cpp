// https://leetcode.com/problems/find-first-palindromic-string-in-the-array

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(string w: words)
        {
            int n=w.length();
            int i=0;
            for(i=0;i<n/2;i++)
            {
                if(w[i]!=w[n-1-i])
                    break;
            }
            if(i==n/2)
                return w;
        }
        return "";
    }
};