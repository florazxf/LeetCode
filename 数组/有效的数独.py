class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        #得到放列的二维数组
        boardlie = zip(*board)  #放列的二维数组
        
        # 得到放三宫格的二维数组
        C=[[],[],[],[],[],[],[],[],[]] #放2x2三宫格的二维数组
        m=0
        for i in range(0,3):
            B = board[m:m+3]
            for j in range(0,3):
                C[m] = C[m] +  B[j][0:3]
                C[m+1] = C[m+1] + B[j][3:6]
                C[m + 2] = C[m + 2] + B[j][6:9]

            m=m+3
        for i in range(9):
            heng = []
            lie = []
            xie = []
            for j in range(9):
                if board[i][j]!=".":
                    heng.append(int(board[i][j]))
                
                if boardlie[i][j]!=".":
                    lie.append(int(boardlie[i][j]))
                
                if C[i][j]!=".":
                    xie.append(int(C[i][j]))
            if len(heng) != len(set(heng)) or len(lie) != len(set(lie)) or len(xie) != len(set(xie)):
                return False  #只要有一个列表有重复元素则不是数独
        return True #全部都不重复才是数独
