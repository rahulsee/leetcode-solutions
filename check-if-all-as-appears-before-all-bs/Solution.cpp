// https://leetcode.com/problems/check-if-all-as-appears-before-all-bs

class Solution {
public:
    bool checkString(string s) {
        int bpos = s.find('b');
        if(bpos == string::npos)
            return true;
        int apos = s.find('a', bpos);
        if(apos == string::npos)
            return true;
        return false;
    }
};