// https://leetcode.com/problems/minimize-deviation-in-array

class Solution {
    public int minimumDeviation(int[] nums) {
        TreeSet<Integer>ts=new TreeSet<>();
        for(int n: nums){
            if(n%2==0)
            ts.add(n);
            else
            ts.add(n*2);
        }
        int diff=ts.last()-ts.first();
        while(ts.last()%2==0){
            int last=ts.pollLast();
            ts.add(last/2);
            diff=Math.min(diff, ts.last()-ts.first());
        }
        return diff;
    }
}