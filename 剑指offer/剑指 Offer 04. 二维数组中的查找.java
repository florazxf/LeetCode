/*
在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
示例:
现有矩阵 matrix 如下：
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
给定 target = 5，返回 true。
给定 target = 20，返回 false。
*/

// 由于每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。 利用这个条件，我们可以从右上角开始遍历，如果当前元素>target，则左移一列；如果当前元素<target,则下移一行

class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        int n = matrix.length;
        if(n==0) return false;
        int m = matrix[0].length;

        int row = 0, col = m-1;

        while(row<n && col>=0){
            if(matrix[row][col]==target){
                return true;
            }
            else if (matrix[row][col]<target){
                row++;
            }
            else{
                col--;
            }
        }
        return false;
    }
}



// 自己做的： 对每一行的数组用二分查找 但是这样没有用到条件每一列也是递增的
class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        int n = matrix.length;
        if(n==0) return false;
        int m = matrix[0].length;
        for (int i = 0; i < n; i++) {
            // 通过二分 查找
            int l = 0;
            int r = m-1;
            while(l<=r){
                int mid = l+(r-l)/2;
                if(matrix[i][mid]==target){
                    return true;
                }
                else if(matrix[i][mid]<target){
                    l = mid +1;
                }
                else{
                    r = mid -1;
                }
            }
        }
        return false;
    }
}
