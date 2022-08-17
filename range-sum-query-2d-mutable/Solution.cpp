// https://leetcode.com/problems/range-sum-query-2d-mutable

class NumMatrix {
public:
    
    int bit[407][407];
    vector<vector<int> >matrix;
    NumMatrix(vector<vector<int>>& matrix) {
        memset(bit, 0, sizeof(bit));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                updateUtil(i,j,matrix[i][j]);
            }
        }
        this->matrix=matrix;
    }
    
    void updateUtil(int row, int col, int val){
        int diff=val;
        row++;
        col++;
        while(row<407){
            int c=col;
            while(col<407){
                // cout<<"UPDATE UTIL "<<row<<"  "<<col<<endl;
                bit[row][col]+=diff;
                col+=(col & -(col));
            }
            col=c;
            row+=(row & (-row));
        }
    }
    
    void update(int row, int col, int val) {
        int diff=val-matrix[row][col];
        matrix[row][col]=val;
        row++;
        col++;
        while(row<407){
            int c=col;
            while(col<407){
                // cout<<"UPDATE "<<row<<"  "<<col<<endl;
                bit[row][col]+=diff;
                col+=(col & -(col));
            }
            col=c;
            row+=(row & (-row));
        }
    }
    
    int getSum(int row, int col){
        int sum=0;
        row++;
        col++;
        while(row>0){
            int c=col;
            while(col>0){
                // cout<<"GET SUM "<<row<<"  "<<col<<endl;
                sum+=bit[row][col];
                col-=(col & -(col));
            }
            col=c;
            row-=(row & (-row));
        }
        return sum;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int a=getSum(row2, col2);
        int b=getSum(row2, col1-1);
        int c=getSum(row1-1, col2);
        int d=getSum(row1-1, col1-1);
        return a+d-(b+c);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */