// https://leetcode.com/problems/average-waiting-time

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double time=customers[0][0]+customers[0][1];
        double wait=customers[0][1];
        for(int i=1;i<customers.size();i++){
            if(time > customers[i][0]){
                wait+=(time-customers[i][0]+customers[i][1]);
                time+=customers[i][1];
            }
            else {
                time=customers[i][0]+customers[i][1];
                wait+=customers[i][1];
            }
        }
        return wait/customers.size();
    }
};