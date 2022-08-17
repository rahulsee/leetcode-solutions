// https://leetcode.com/problems/maximize-sum-of-array-after-k-negations

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        priority_queue<int, vector<int>, greater<int>>pq;
        for(int num: A){
            pq.push(num);
        }
        for(int i=0;i<K;i++){
            int mini=pq.top();
            pq.pop();
            mini=mini*(-1);
            pq.push(mini);
        }
        int ans=0;
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};