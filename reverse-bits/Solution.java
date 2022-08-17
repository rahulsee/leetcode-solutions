// https://leetcode.com/problems/reverse-bits

public class Solution {
    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        int res=0;
        for(int i=31;i>=0;i--){
            if((n & 1)==1)
            {
                res=res+(1<<i);
            }
            n=n>>1;
        }
        return res;
    }
}