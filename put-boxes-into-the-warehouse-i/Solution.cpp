// https://leetcode.com/problems/put-boxes-into-the-warehouse-i

class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        for(int i=1;i<warehouse.size();i++){
            warehouse[i]=min(warehouse[i], warehouse[i-1]);
        }
        int cur=0;
        sort(boxes.begin(), boxes.end());
        for(int i=warehouse.size()-1;i>=0;i--){
            if(cur<boxes.size() && warehouse[i]>=boxes[cur]){
                cur++;
            }
        }
        return cur;
    }
};