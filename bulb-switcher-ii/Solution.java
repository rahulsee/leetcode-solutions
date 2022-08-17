// https://leetcode.com/problems/bulb-switcher-ii

class Solution {
    public int flipLights(int n, int m) {
        m=Math.min(m,4);
        n=Math.min(n,3);
        int table[][]=new int[][]{
            {1,3,4,4,4},
            {1,2,2,2,2},
            {1,3,4,4,4},
            {1,4,7,8,8}
        };
        return table[n][m];
    }
}