// https://leetcode.com/problems/can-place-flowers

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        vector<int>op;
        for(int i=0;i<flowerbed.size();i++) {
            if(flowerbed[i]==1)
                op.push_back(i);
        }
        if(op.size()==0){
            return (flowerbed.size()+1)/2>=n;
        }
        int slots=op[0];
        int ans=0;
        ans=ans+slots/2;
        for(int i=1;i<op.size();i++){
            slots=op[i]-op[i-1]-1;
            ans=ans+(slots-1)/2;
        }
        slots=flowerbed.size()-op[op.size()-1]-1;
        ans=ans+slots/2;
        return ans>=n;
    }
};