// https://leetcode.com/problems/furthest-building-you-can-reach

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int>pq;
        for(int i=1;i<heights.size();i++){
            int diff=heights[i]-heights[i-1];
            if(diff<=0)
                continue;
            bricks-=diff;
            pq.push(diff);
            if(bricks < 0){
                bricks+=pq.top();
                pq.pop();
                if(ladders > 0)
                ladders--;
                else
                return i-1;
            }
        }
        return heights.size()-1;
    }
};