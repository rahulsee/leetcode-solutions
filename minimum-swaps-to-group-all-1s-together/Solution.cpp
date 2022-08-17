// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together

class Solution {
public:
    int minSwaps(vector<int>& data) {
        int n=data.size();
        int oc=0;
        for(int i=0;i<n;i++){
            if(data[i]==1)
                oc++;
        }
        for(int i=1;i<n;i++){
            data[i]+=data[i-1];
        }
        if(oc==0 || oc==1)
            return 0;
        int maxi=data[oc-1];
        for(int i=oc;i<n;i++){
            maxi=max(maxi, data[i]-data[i-oc]);
        }
        return oc-maxi;
    }
};