// https://leetcode.com/problems/hamming-distance

class Solution {
    public int hammingDistance(int x, int y) {
        int num=x ^ y;
        int count=0;
        while(num > 0){
            int result=num & 1;
            count+=result;
            num=num >> 1;
        }
        return count;
    }
}