// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers

class Solution {
public:
    int minPartitions(string n) {
        int maxi=0;
        for(char ch: n){
            maxi=max(maxi, ch-'0');
        }
        return maxi;
    }
};