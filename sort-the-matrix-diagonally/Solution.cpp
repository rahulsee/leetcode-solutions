// https://leetcode.com/problems/sort-the-matrix-diagonally

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int rows=mat.size();
        int cols=mat[0].size();
        for(int i=1;i<cols;i++){
            int p=0;
            int q=i;
            vector<int>tmp;
            while(p<rows && q<cols){
                tmp.push_back(mat[p][q]);
                p++;
                q++;
            }
            sort(tmp.begin(), tmp.end());
            p=0;
            q=i;
            int x=0;
            while(p<rows && q<cols){
                mat[p][q]=tmp[x++];
                p++;
                q++;
            }
        }
        for(int i=0;i<rows;i++){
            int p=i;
            int q=0;
            vector<int>tmp;
            while(p<rows && q<cols){
                tmp.push_back(mat[p][q]);
                p++;
                q++;
            }
            sort(tmp.begin(), tmp.end());
            p=i;
            q=0;
            int x=0;
            while(p<rows && q<cols){
                mat[p][q]=tmp[x++];
                p++;
                q++;
            }
        }
        return mat;
    }
};