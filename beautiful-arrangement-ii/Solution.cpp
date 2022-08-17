// https://leetcode.com/problems/beautiful-arrangement-ii

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int>ans;
        int start=1;
        int end=n;
        for(int i=0;i<(n-k-1);i++){
            ans.push_back(start);
            start++;
        }
        while(start<=end){
            ans.push_back(start);
            if(start!=end)
                ans.push_back(end);
            start++;
            end--;
        }
        return ans;
    }
};