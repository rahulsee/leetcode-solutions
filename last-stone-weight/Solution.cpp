// https://leetcode.com/problems/last-stone-weight

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int s: stones){
            pq.push(s);   
        }
        while(pq.size()>0){
            int x=pq.top();
            pq.pop();
            if(pq.size()>=1)
            {
                int y=pq.top();
                pq.pop();
                if(x!=y){
                    pq.push(x-y);
                }
            }
            else {
                return x;      
            }
        }
        return 0;
    }
};