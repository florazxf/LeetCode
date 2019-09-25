'''
给定一个 n × n 的二维矩阵表示一个图像。

将图像顺时针旋转 90 度。

说明：

你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。

示例 1:

给定 matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
示例 2:

给定 matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

原地旋转输入矩阵，使其变为:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
'''



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
