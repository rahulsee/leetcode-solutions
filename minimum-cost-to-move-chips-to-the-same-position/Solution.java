// https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position

class Solution {
    public int minCostToMoveChips(int[] position) {
        int oddCount=0;
        for(int i=0;i<position.length;i++){
            if((position[i] & 1) == 1){
                oddCount++;
            } 
        }
        return Math.min(oddCount, position.length-oddCount);
    }
}