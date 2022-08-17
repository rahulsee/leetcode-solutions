// https://leetcode.com/problems/smallest-integer-divisible-by-k

class Solution {
public:
    int smallestRepunitDivByK(int K) {
        int num=1;
        unordered_map<int, int>rems;
        int len=1;
        while(true){
            if(rems.find(num%K)!=rems.end()) 
                break;
            rems.insert({num%K, len});
            num=((num*10)%K+1)%K;
            len++;
        }
        if(rems.find(0)!=rems.end())
            return rems[0];
        return -1;
    }
};