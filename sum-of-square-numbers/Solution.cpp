// https://leetcode.com/problems/sum-of-square-numbers

class Solution {
public:
    bool judgeSquareSum(int c) {
        long x=c;
        unordered_set<long>us;
        long i=0;
        while((i*i)<=x)
        {
            us.insert(i*i);
            i++;
        }
        for(long num: us)
        {
            if(us.find(c-num)!=us.end())
                return true;
        }
        return false;
    }
};