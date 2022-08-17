// https://leetcode.com/problems/mirror-reflection

class Solution {
public:
    int mirrorReflection(int p, int q) {
        int g=__gcd(p,q);
        p=p/g;
        q=q/g;
        if(p%2==0)
            return 2;
        if(q%2==0)
            return 0;
        return 1;
    }
};