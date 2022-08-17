// https://leetcode.com/problems/combination-sum

class Solution {
public:
    unordered_set<int>visited;
    void solve(int cur, vector<vector<int> >&vec, vector<int>arr, vector<int>&ans, int target) {
                
        if(target < 0){
            return;
        }
    
        if(target==0){
            vec.push_back(ans);
            return;
        }
        
        if(cur==arr.size()){
            return;
        }
        ans.push_back(arr[cur]);
        solve(cur, vec, arr, ans, target-arr[cur]);
        ans.pop_back();
        solve(cur+1, vec, arr, ans, target);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> >ans;
        vector<int>tmp;
        solve(0, ans, candidates, tmp, target);
        return ans;
    }
};