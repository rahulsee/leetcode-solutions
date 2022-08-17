// https://leetcode.com/problems/pascals-triangle-ii

class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        pascal=[0]*(rowIndex+1)
        pascal[0]=1
        for i in range(rowIndex+1):
            for j in range(i, -1, -1):
                if j==0:
                    pascal[j]=1
                else:
                    pascal[j]=pascal[j-1]+pascal[j]
        return pascal