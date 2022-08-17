// https://leetcode.com/problems/palindrome-number

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        if(x%10==0 && x!=0)
            return false;
        long long temp=x;
        long long y=0;
        while(temp>0)
        {
            y=y*10+temp%10;
            temp/=10;
        }
        return x==y;
    }
};