// https://leetcode.com/problems/find-smallest-common-element-in-all-rows

class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        unordered_map<int,int>freq;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                freq[mat[i][j]]++;
            }
        }
        int ans=numeric_limits<int>::max();
        for(auto it=freq.begin();it!=freq.end();it++){
            if(it->second==mat.size()){
                ans=min(ans, it->first);
            }
        }
        return ans==numeric_limits<int>::max() ? -1 : ans;
    }
};