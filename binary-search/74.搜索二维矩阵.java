/*
编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：


	每行中的整数从左到右按升序排列。
	每行的第一个整数大于前一行的最后一个整数。


示例 1:

输入:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
输出: true


示例 2:

输入:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
输出: false
*/

//二分查找：自己做的

/*
时间复杂度：标准的二分查找 O(log(mn))
空间复杂度：O(1)
*/
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length;
        if(m==0){
            return false;
        }
        int n = matrix[0].length;

        int left = 0;
        int right = m*n-1;

        while(left<=right){
            int mid = left+(right-left)/2;
            int i = mid/n;
            int j = mid%n;
            if(matrix[i][j]==target){
                return true;
            }
            else if(matrix[i][j]<target){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return false;

    }
}
