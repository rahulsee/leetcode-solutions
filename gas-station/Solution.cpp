// https://leetcode.com/problems/gas-station

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=cost.size();
        vector<int>debt(n,0);
        vector<int>owed(n,0);
        for(int i=0;i<n;i++)
        {
            debt[i]=cost[i]-gas[i];
            owed[i]=gas[i]-cost[i];
        }
        for(int i=n-2;i>=0;i--)
            owed[i]+=owed[i+1];
        for(int i=1;i<n;i++)
            debt[i]+=debt[i-1];
        int max_pressure=0;
        for(int i=0;i<n;i++)
            max_pressure=max(max_pressure, debt[i]);
        for(int i=n-1;i>=0;i--)
        {
            if(owed[i]>=max_pressure)
                return i;
        }
        return -1;
    }
};