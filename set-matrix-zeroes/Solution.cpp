// https://leetcode.com/problems/set-matrix-zeroes

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        bool rowZero=false;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]==0){
                    if(i>0)
                        matrix[i][0]=0;
                    else 
                        rowZero=true;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<rows;i++) {
            for(int j=1;j<cols;j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if(matrix[0][0]==0){
            for(int i=0;i<rows;i++){
                matrix[i][0]=0;
            }
        }
        if(rowZero){
            for(int i=0;i<cols;i++){
                matrix[0][i]=0;
            }
        }
    }
};