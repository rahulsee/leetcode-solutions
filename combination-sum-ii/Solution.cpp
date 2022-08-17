// https://leetcode.com/problems/combination-sum-ii

class Solution {
public:
    
    void solve(vector<int>&counts, vector<vector<int> >&ans, vector<int>&tmp, int &target, int cur){
        
        if(target==0){
            ans.push_back(tmp);
            return;
        }
        
        for(int i=cur;i<=50;i++){
            if(counts[i] && target>=i){
                counts[i]--;
                target-=i;
                tmp.push_back(i);
                solve(counts, ans, tmp, target, i);
                target+=i;
                counts[i]++;
                tmp.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>counts(51);
        for(int n: candidates){
            counts[n]++;
        }
        vector<vector<int> >ans;
        vector<int>tmp;
        int num=target;
        solve(counts, ans, tmp, num, 1);
        return ans;
    }
};