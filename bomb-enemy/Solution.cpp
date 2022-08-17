// https://leetcode.com/problems/bomb-enemy

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        unordered_map<int,int>rc;
        unordered_map<int,int>cc;
        int max1[grid.size()][grid[0].size()];
        memset(max1, 0, sizeof(max1));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='E'){
                    rc[i]++;
                    cc[j]++;
                }
                else if(grid[i][j]=='0'){
                    max1[i][j]=rc[i]+cc[j];
                }
                else {
                    rc[i]=0;
                    cc[j]=0;
                }
            }
        }
        rc.clear();
        cc.clear();
        int max2[grid.size()][grid[0].size()];
        memset(max2, 0, sizeof(max2));
        for(int i=grid.size()-1;i>=0;i--){
            for(int j=grid[i].size()-1;j>=0;j--){
                if(grid[i][j]=='E'){
                    rc[i]++;
                    cc[j]++;
                }
                else if(grid[i][j]=='0'){
                    max2[i][j]=rc[i]+cc[j];
                }
                else {
                    rc[i]=0;
                    cc[j]=0;
                }
            }
        }
        int maxi=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                maxi=max(maxi,max1[i][j]+max2[i][j]);
            }
        }
        return maxi;
    }
};