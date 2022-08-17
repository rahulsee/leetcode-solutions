// https://leetcode.com/problems/number-of-times-binary-string-is-prefix-aligned

class Solution {
    public int numTimesAllBlue(int[] light) {
        int rightMost=-1;
        int count=0;
        for(int i=0;i<light.length;i++){
            rightMost=Math.max(rightMost,light[i]);
            if(rightMost==i+1){
                count++;
            }
        }
        return count;
    }
}