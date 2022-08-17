// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero

class Solution {
public:
    
    unordered_map<int,int>m;
    
    int numberOfSteps (int num) {
        if(num==0)
            return 0;
        if(num==1)
            return 1;
        if(m.find(num)!=m.end())
            return m[num];
        m[num]=((num%2==0)?numberOfSteps(num/2):numberOfSteps(num-1))+1;
        return m[num];
    }
};