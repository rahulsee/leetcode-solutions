// https://leetcode.com/problems/rotate-image

class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n=len(matrix)
        for i in range(n):
            for j in range(i+1):
                x,y=j,i
                matrix[i][j], matrix[x][y]=matrix[x][y], matrix[i][j]
        
        for i in range(n):
            x=0
            y=n-1
            while x<=y:
                matrix[i][x], matrix[i][y]=matrix[i][y],matrix[i][x]
                x+=1
                y-=1
            