// https://leetcode.com/problems/game-of-life

class Solution:
    
    def within_range(self, x,y, board):
        return x>=0 and x<len(board) and y>=0 and y<len(board[0])
    
    def was_alive(self, val):
        return val==-1 or val==-3 or val==-4
    
    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j]==0:
                    board[i][j]=-2
                else:
                    board[i][j]=-1
                
        for i in range(len(board)):
            for j in range(len(board[0])):
                is_live = (board[i][j]==-1)
                live_cells=0
                if self.within_range(i-1,j-1, board):
                    live_cells+=int(self.was_alive(board[i-1][j-1]))
                if self.within_range(i-1, j, board):
                    live_cells+=int(self.was_alive(board[i-1][j]))
                if self.within_range(i-1, j+1, board):
                    live_cells+=int(self.was_alive(board[i-1][j+1]))
                if self.within_range(i, j-1, board):
                    live_cells+=int(self.was_alive(board[i][j-1]))
                if self.within_range(i, j+1, board):
                    live_cells+=int(self.was_alive(board[i][j+1]))
                if self.within_range(i+1, j-1, board):
                    live_cells+=int(self.was_alive(board[i+1][j-1]))
                if self.within_range(i+1, j, board):
                    live_cells+=int(self.was_alive(board[i+1][j]))
                if self.within_range(i+1, j+1, board):
                    live_cells+=int(self.was_alive(board[i+1][j+1]))
                
                
                if is_live and live_cells<2:
                    board[i][j]=-3
                elif is_live and (live_cells==2 or live_cells==3):
                    board[i][j]=-1
                elif is_live and live_cells>3:
                    board[i][j]=-4
                elif not is_live and live_cells==3:
                    board[i][j]=-5
                        
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j]==-1:
                    board[i][j]=1
                elif board[i][j]==-2 or board[i][j]==-3 or board[i][j]==-4:
                    board[i][j]=0
                elif board[i][j]==-5:
                    board[i][j]=1
            