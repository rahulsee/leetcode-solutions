// https://leetcode.com/problems/island-perimeter

class Solution {
    
    int rows;
    int cols;
    boolean valid(int x,int y){
        return x>=0 && x<rows && y>=0 && y<cols;
    }
    
    int neighbourCount(int [][]grid, int x,int y){
        int count=0;
        if(valid(x-1,y) && grid[x-1][y]==1)
            count++;
        if(valid(x+1,y) && grid[x+1][y]==1)
            count++;
        if(valid(x,y-1) && grid[x][y-1]==1)
           count++;
        if(valid(x,y+1) && grid[x][y+1]==1)
           count++;
        return count;
    }
    
    public int islandPerimeter(int[][] grid) {
        rows=grid.length;
        cols=grid[0].length;
        int sum=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1)
                    sum=sum+4-neighbourCount(grid,i,j);
            }
        }
        return sum;
    }
}