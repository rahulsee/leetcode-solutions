// https://leetcode.com/problems/check-array-formation-through-concatenation

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, vector<int> >g;
        for(int i=0;i<pieces.size();i++){
            g[pieces[i][0]]=pieces[i];
        }
        vector<int>vec;
        for(int i=0;i<arr.size();i++){
            vector<int>tmp=g[arr[i]];
            for(int num: tmp)
                vec.push_back(num);
        }
        if(vec.size()!=arr.size())
            return false;
        for(int i=0;i<vec.size();i++) {
            if(vec[i]!=arr[i])
                return false;
        }
        return true;
    }
};