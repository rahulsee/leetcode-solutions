// https://leetcode.com/problems/number-of-submatrices-that-sum-to-target

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        for(int i=0;i<rows;i++){
            for(int j=1;j<cols;j++){
                matrix[i][j]+=matrix[i][j-1];
            }
        }
        int ans=0;
        for(int r1=0;r1<rows;r1++){
            vector<int>vec(cols,0);
            for(int r2=r1;r2<rows;r2++){
                for(int i=0;i<cols;i++){
                    vec[i]+=matrix[r2][i];
                }
                unordered_map<int, int>us;
                int cnt=0;
                for(int num: vec){
                    if(us.find(num-target)!=us.end()){
                        cnt+=us[num-target];
                    }
                    if(num==target){
                        cnt++;
                    }
                    us[num]++;
                }
                ans+=cnt;
            }
        }
        return ans;
    }
};