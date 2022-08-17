// https://leetcode.com/problems/flipping-an-image

class Solution {
    public int[][] flipAndInvertImage(int[][] A) {
        if(A==null)
            return A;
        if(A.length==0)
            return A;
        if(A[0].length==0)
            return A;
        for(int i=0;i<A.length;i++){
            int n=A[i].length;
            for(int j=0;j<n/2;j++)
            {
                int tmp=A[i][j];
                A[i][j]=A[i][n-1-j];
                A[i][n-1-j]=tmp;
            }
            for(int j=0;j<n;j++)
                A[i][j]=1-A[i][j];
        }
        return A;
    }
}