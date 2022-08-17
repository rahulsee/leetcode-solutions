// https://leetcode.com/problems/maximum-units-on-a-truck

class Solution {
public:
    
    struct compare {
        bool operator()(vector<int>a, vector<int>b){
            return a[1]>b[1];
        }
    };
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), compare());
        int ans=0;
        for(int i=0;i<boxTypes.size();i++){
            if(boxTypes[i][0] <= truckSize){
                truckSize-=boxTypes[i][0];
                ans+=(boxTypes[i][0]*boxTypes[i][1]);
            }
            else {
                ans+=(truckSize * boxTypes[i][1]);
                truckSize=0;
            }   
        }
        return ans;
    }
};