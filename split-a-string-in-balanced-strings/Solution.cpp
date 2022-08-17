// https://leetcode.com/problems/split-a-string-in-balanced-strings

class Solution {
public:
    int balancedStringSplit(string s) {
        int len=s.length();
        int count=0;
        int r=0;
        int l=0;
        for(int i=0;i<len;i++){
            if(s[i]=='R')
                r++;
            else
                l++;
            if(l==r){
                l=r=0;
                count++;
            }
        }
        return count;
    }
};