// https://leetcode.com/problems/remove-palindromic-subsequences

class Solution {
public:
    int removePalindromeSub(string s) {
        string t;
        t=s;
        reverse(t.begin(), t.end());
        if(t==s)
            return 1;
        return 2;
    }
};