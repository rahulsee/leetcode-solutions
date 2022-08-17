// https://leetcode.com/problems/poor-pigs

class Solution {
    public int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int slots=minutesToTest/minutesToDie;
        return (int)Math.ceil((double)Math.log(buckets)/Math.log((double)slots+1));
    }
}