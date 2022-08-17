// https://leetcode.com/problems/angle-between-hands-of-a-clock

class Solution {
    public double angleClock(int hour, int minutes) {
        double a=(double)minutes/5;
        double val;
        if(hour < a)
        val=(Math.abs(hour-a))*30-(double)minutes/2;
        else
        val=(Math.abs(hour-a))*30+(double)minutes/2;
        val=Math.abs(val);
        return Math.min(val,360-val);
    }
}