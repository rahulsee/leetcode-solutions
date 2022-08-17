// https://leetcode.com/problems/consecutive-characters

class Solution {
    public int maxPower(String s) {
        int maxPow=1;
        int pow=1;
        char []arr=s.toCharArray();
        for(int i=1;i<arr.length;i++){
            if(arr[i]==arr[i-1]){
                pow++;
            }
            else {
                pow=1;
            }
            maxPow=Math.max(pow,maxPow);
        }
        return maxPow;
    }
}