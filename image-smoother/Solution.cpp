// https://leetcode.com/problems/image-smoother

class Solution {
public:
    
    bool valid(int x,int y,int rows, int cols)
    {
        return x>=0 && x<rows && y>=0 && y<cols;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int rows=M.size();
        int cols=M[0].size();
        vector<vector<int> >N(M);
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                int sum=0;
                int count=0;
                for(int p=-1;p<=1;p++)
                {
                    for(int q=-1;q<=1;q++)
                    {
                        if(valid(i+p,j+q,rows,cols))
                        {
                            sum+=M[i+p][j+q];
                            count++;
                        }
                    }
                }
                N[i][j]=sum/count;
                
            }
        }
        return N;
    }
};