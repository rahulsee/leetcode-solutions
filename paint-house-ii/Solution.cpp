// https://leetcode.com/problems/paint-house-ii

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n=costs.size();
        int k=costs[0].size();
        for(int i=1;i<n;i++){
            vector<int>lr(k);
            vector<int>rl(k);
            lr[0]=costs[i-1][0];
            for(int j=1;j<k;j++){
                lr[j]=min(lr[j-1], costs[i-1][j]);
            }
            rl[k-1]=costs[i-1][k-1];
            for(int j=k-2;j>=0;j--){
                rl[j]=min(rl[j+1], costs[i-1][j]);
            }
            for(int j=0;j<k;j++){
                if(j==0)
                    costs[i][j]+=rl[j+1];
                else if(j==k-1)
                    costs[i][j]+=lr[j-1];
                else 
                    costs[i][j]+=min(lr[j-1], rl[j+1]);
            }
        }
        int ans=numeric_limits<int>::max();
        for(int i=0;i<k;i++){
            ans=min(ans, costs[n-1][i]);
        }
        return ans;
    }
};