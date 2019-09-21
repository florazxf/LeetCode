class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)

        m = n-1
        i = 0

        for i in range(int(n/2)):  #有int(n/2)个圈需要旋转
            for j in range(i, m):  # 控制每一个圈的第几个要旋转的组
                x1 = i #注意x1必须写这里不能写在j循环外
                y1 = j
                for z in range(0, 3):  # 每个组的4个元素逆时针两两交换三次
                    x2 = n - y1 - 1
                    y2 = x1
                    # 用异或的方式进行a和b的交换
                    matrix[x1][y1] = matrix[x1][y1] ^ matrix[x2][y2]
                    matrix[x2][y2] = matrix[x1][y1] ^ matrix[x2][y2]
                    matrix[x1][y1] = matrix[x1][y1] ^ matrix[x2][y2]
                    x1 = x2
                    y1 = y2
            m = m - 1
